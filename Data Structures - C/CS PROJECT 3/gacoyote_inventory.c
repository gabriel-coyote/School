#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_HASH 100 			//Assuming no more than 100 items for HASH TABLE
#define A .618033					//For Hash Function: Multiplication Method
#define checkout 1				//For Menu System: Switch Case
#define inventory 2				//For Menu System: Switch Case
#define quit 3						//For Menu System: Switch Case
#define help 4						//For Menu System: Switch Case


//STRUCT: 
//Inventory Items represented by the following struct
typedef struct items{
	int Key;								//Item's Key
	char Name[50];					//Name of the item
	int Threshold;					//Point at which store needs to order more of that item
	int Stock;							//Number of items currently in stock
	float Price;						//Price of that item $
} Items_t;


//STRUCT: 
//Customers represented by the following struct
typedef struct customers{
	char Name[50];						//Customers Name
	float Cash;								//Customer's wallet
	char Grocery_List[500];		//Customer's grocery list as string; good for purchasing 50 different items
} Customers_t;


//FUNCTION PROTOTYPES
void menu(Items_t Hash_Table[MAX_HASH]);												//Menu System: With switch case & while loop
void checkout_customers(char *, Items_t Hash_Table[MAX_HASH]);	//Main Menu Switch Case Functions
void inventory_submenu(Items_t Hash_Table[MAX_HASH]);						//Main Menu Switch Case Functions
void close_program(Items_t Hash_Table[MAX_HASH]);								//Main Menu Switch Case Functions
void help_commands();																						//Prints the Syntax for menu Commands

int option_select(char *);															//Returns int for Menu's Function Switch case


int hash_function(int);																	//Returns Hash value (integer) for a Key
void empty_Hash_Table(Items_t Hash_Table[MAX_HASH]);		//Numbers are '-1' and Name to "" ; to indicate empty
void populate_Hash_Table(Items_t Hash_Table[MAX_HASH]);	//When program starts up; populate Hash Table
int size_of_queue(char *);															//Returns how many customers to queue
void fill_customer_queue(char *, Customers_t Customer_queue[], int);//Fills Array of Customer Structs;with entered txt file 

void process_customers(char *, Customers_t Customer_queue[], Items_t Hash_Table[MAX_HASH], int); 
int process_order(FILE *, char *, float *, float *, Items_t Hash_Table[MAX_HASH]);	

void deduct_inventory(char *, Items_t Hash_Table[MAX_HASH]);	//Deducts item from inventory
void warning_restock(Items_t Hash_Table[MAX_HASH]);						//Prints restock message if needed
void restock_all(Items_t Hash_Table[MAX_HASH]);								//Restocks all items





////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION

int main(void) {

  Items_t Hash_Table[MAX_HASH];									//Hash Table with Structs as items; holds 100 items										
 	empty_Hash_Table(Hash_Table);												//Set values indicating empty to all items in Hash_Table
	populate_Hash_Table(Hash_Table);										//When Program starts up; Populate Hash Table

	menu(Hash_Table);


  return 0;
}
////////////////////////////////////////////////////////////////////////////




//HASH FUNCTION:  
//Multiplication Method - Knuth
int hash_function(int key){
	int hash_value =   floor (MAX_HASH * ( (key * A - floor(key * A) )));
	return hash_value;
}


/*************************************************************************/


//SETS HASH TABLE ITEMS TO EMPTY: 
//Numbers are '-1' and Name to "" to indicate empty
void empty_Hash_Table(Items_t Hash_Table[MAX_HASH]){
	for(int i = 0; i < MAX_HASH; i++){
		Hash_Table[i].Key = -1;							
		strcpy(Hash_Table[i].Name, "");		
		Hash_Table[i].Threshold = -1;		
		Hash_Table[i].Stock = -1;						
		Hash_Table[i].Price = -1;	
	}
}

/*************************************************************************/


//POPULATE HASH TABLE FUNCTION:  
//With "inventory.txt", when program starts up
void populate_Hash_Table(Items_t Hash_Table[MAX_HASH]){
	char line_str[1000];																	//Holds String from fgets
	FILE *fp;																							//FILE pointer
	fp = fopen("inventory.txt", "r");											//Opens inventory.txt


	if(fp == NULL){
		printf("Could not open File \"inventory.txt\"");
	}else{
		
		while(fgets(line_str, 1000, fp) != NULL){						//Gets Lines from txt file; assigns to "line_str"
			/*printf("\nLine Str: %s", line_str);*/

			char stop_quotes[] = "\"";												//To parse string; stops at quatation mark
			char stop_comma[] = ",";													//To parse string; stops at comma
			char end[] = "}";																	//To parse string; stops at final '}'

			char key[10];
			char name[50];
			char threshold[25];
			char stock[25];
			char price[25];

			memset(key, 0, sizeof key);												//memset function kinda of "emptys" the string
			memset(name, 0, sizeof name);
			memset(threshold, 0, sizeof threshold);
			memset(stock, 0, sizeof stock);
			memset(price, 0, sizeof price);

			int index = 1;																		//Index is at first digit in line_str
			int parse_index = 0;															//Setting Parse index to zero
			while(line_str[index] != stop_comma[0]){					//Getting Key string from line_str
				key[parse_index] = line_str[index];					
				parse_index++;
				index++;
			}					
			

			index += 3;																				//Index is now at the first Letter of Name
			parse_index = 0;																	//Resetting parse index to zero
			while(line_str[index] != stop_quotes[0]){					//Getting Name string from line_str
				name[parse_index] = line_str[index];
				parse_index++;
				index++;
			}

			
			index += 3;																				//Index is now at the first digit of threshold 
			parse_index = 0;																	//Resetting parse index to zero
			while(line_str[index] != stop_comma[0]){					//Getting Threshold string from line_str
				threshold[parse_index] = line_str[index];	
				parse_index++;
				index++;
			}


			index += 2;																				//Index is now at the first digit of stock
			parse_index = 0;																	//Resetting parse index to zero
			while(line_str[index] != stop_comma[0]){					//Getting Stock string from line_str
				stock[parse_index] = line_str[index];
				parse_index++;
				index++;
			}


			index += 2;																				//Index is now at the first digit of price
			parse_index = 0;																	//Resetting parse Index to zero
			while(line_str[index] != end[0]){									//Getting Price string from line_str
				price[parse_index] = line_str[index];
				parse_index++;
				index++;
			}
			
			
			Hash_Table[hash_function(atoi(key))].Key = atoi(key);								//Assigning Key to Struct	
			strcpy(Hash_Table[hash_function(atoi(key))].Name, name);						//Assigning Name to Struct	
			Hash_Table[hash_function(atoi(key))].Threshold = atoi(threshold);		//Assigning Threshold to Struct	
			Hash_Table[hash_function(atoi(key))].Stock = atoi(stock);						//Assigning Stock to Struct	
			Hash_Table[hash_function(atoi(key))].Price = atof(price);						//Assigning Price to Struct	
			
			/*
			printf("\n");
			printf("Hash_Table[%d]:\n", hash_function(atoi(key)));
			printf("\tKey = %d\n", Hash_Table[hash_function(atoi(key))].Key);
			printf("\tName = %s\n", Hash_Table[hash_function(atoi(key))].Name);
			printf("\tThreshold = %d\n", Hash_Table[hash_function(atoi(key))].Threshold);
			printf("\tStock = %d\n",Hash_Table[hash_function(atoi(key))].Stock );
			printf("\tPrice = %.2lf\n",Hash_Table[hash_function(atoi(key))].Price );
			*/

		}
	}

	fclose(fp);																							//Close FILE pointer; to inventory.txt
}



/*************************************************************************/



//QUEUE SIZE FUNCTION: 
//Returns how many customers to queue
int size_of_queue(char *filename){
	char lines[1000];
	int Q_size = 0;

	FILE *fp;
	fp = fopen(filename, "r");

	if(fp == NULL){
		printf("\n:::: Could not open file \"%s\"", filename);
		return -1;
	}else{
		while(fgets(lines, 1000, fp) != NULL){							//Each line is one customer
			Q_size++;																					//While we still get lines; increase Queue size by 1
		}
	}

	fclose(fp);
	return Q_size;
}



/*************************************************************************/



//FILLS CUSTOMER QUEUE FUNCTION: 
//Fills queue array (of customer structs) with data from inputted txt file
void fill_customer_queue(char *filename, Customers_t Customer_queue[], int queue_size){
	FILE *fp;
	fp = fopen(filename,"r");																//Opening Customer File to be read

	char data_str[1000];																		//Holds line string
	int customer_index = queue_size - queue_size;						//Used as index in queue array of customers structs


	while(fgets(data_str, 1000, fp) != NULL){
		//printf("\nData str %d: %s\n", customer_index,data_str);
		

		char stop_quotes[] = "\"";														//To parse string: stops at quotes
		char stop_comma[] = ",";															//To parse string: stops at comma
		char stop_bracket[] = "]";														//To parse string: stops at ending bracket
		char end[] = "\n";																		//Added to end of grocery list string; marks end

		char name[50];
		char cash[20];
		char grocery_list[500];

		memset(name, 0, sizeof name);													//memset function kinda of "emptys" the string
		memset(cash, 0, sizeof cash);
		memset(grocery_list, 0, sizeof grocery_list);


		int data_index = 2;																		//Index is at the first letter of customer name
		int parse_index = 0;																	//Resetting parse index to zero
		while(data_str[data_index] != stop_quotes[0]){				//Getting Name string from data_str
			name[parse_index] = data_str[data_index];
			data_index++;
			parse_index++;
		}


		data_index += 3;																			//Index is at the first digit of cash
		parse_index = 0;																			//Restting Parse index to zero								
		while(data_str[data_index] != stop_comma[0]){					//Getting Cash string from data_str
			cash[parse_index] = data_str[data_index];
			data_index++;
			parse_index++;
		}


		data_index += 3;																			//Index is now at the first "{" in grocery list
		parse_index = 0;																			//Resetting parse index to zero
		while(data_str[data_index] != stop_bracket[0]){				//Getting grocery list string without "[" & "]"
			grocery_list[parse_index] = data_str[data_index];
			data_index++;
			parse_index++;
		}
		grocery_list[parse_index] = end[0];										//Adds "\n" to indicate end of grocery list str



		strcpy(Customer_queue[customer_index].Name, name);									//Assiging Name to Struct
		Customer_queue[customer_index].Cash = atof(cash);										//Assigning float cash to Struct
		strcpy(Customer_queue[customer_index].Grocery_List, grocery_list);	//Assigning Grocery List to Struct
/*
		printf("\n\tName Str: %s", name);
		printf("\n\tCash Str: %s", cash);
		printf("\n\tG_List Str: %s\n", grocery_list);
*/
		customer_index++;
	}
}



/*************************************************************************/


//WARNING RESTOCK FUNCTION
//Prints restock message if restock is needed
void warning_restock(Items_t Hash_Table[MAX_HASH]){

	int restock = 0;																			//A flag; If 1 then print restock warning

	for(int i = 0; i < MAX_HASH; i++){									  //Check if stock < threshold
		if(Hash_Table[i].Key == -1){												//Checks if struct is empty
			/* Struct is empty; Do nothing */
		}else if( Hash_Table[i].Stock < Hash_Table[i].Threshold ){	
			restock = 1;
		}
	}



	if( restock == 1){
		printf("\nWarning! The following Item(s) may need to be restocked:");

		for(int i = 0; i < MAX_HASH; i++){									  //Check if stock < threshold
			if(Hash_Table[i].Key == -1){												//Checks if struct is empty
				/* Struct is empty; Do nothing */
			}else if( Hash_Table[i].Stock < Hash_Table[i].Threshold ){	
				printf("\n%d (%s) : %d remain in stock, replenishment threshold is %d", Hash_Table[i].Key, Hash_Table[i].Name, Hash_Table[i].Stock, Hash_Table[i].Threshold);
			}
	 	}
	
	}


}


/*************************************************************************/


//DEDUCT INVENTORY FUNCTION
//Deducts items from inventory 
void deduct_inventory(char *grocery_list, Items_t Hash_Table[MAX_HASH]){

	char end_comma[] = ",";																//For parsing: stops at comma
	char end_bracket[] = "}";														//For parsing: stops at bracket
	char end_list[] = "\n";															//For parsing: stops at newline

	
	int g_index = 1;																		//Index is at the first digit of key
	int k_index;																				//For parsing: key string index
	int a_index;																				//For parsing: amount string index

	char key[10];																				//Key string
	char amount[5];																			//Amount string

	
	//Processing Grocery List & Total
	while(grocery_list[g_index] != end_list[0]){				//While grocery list doesnt end

		k_index = 0;																			//Restting Key index to zero for item
		a_index = 0;																			//Restting amount index to zero for item

		memset(amount, 0, sizeof amount);									//Kinda of emptying string: amount
		memset(key, 0, sizeof key);												//Kinda of emptying string: key


		while(grocery_list[g_index] != end_comma[0]){
			key[k_index] = grocery_list[g_index];						//Getting Key string from list
			g_index++;
			k_index++;
		}																									

		g_index += 2;																			//Index is now at the first digit of amount
		while(grocery_list[g_index] != end_bracket[0]){
			amount[a_index] = grocery_list[g_index];				//Getting Amount string from list
			g_index++;	
			a_index++;
		}


		g_index += 1;																			//Index is now at comma OR "\n"
		if(grocery_list[g_index] == end_comma[0]){				//If current index is comma
			g_index += 3;																		//Increase index for next grocery item
		}		

		//printf("\nBefore: %s x%d", Hash_Table[hash_function(atoi(key))].Name, Hash_Table[hash_function(atoi(key))].Stock);
		Hash_Table[hash_function(atoi(key))].Stock -= atoi(amount);			//Deduct from stock
		//printf("\nAfter: %s x%d\n\n", Hash_Table[hash_function(atoi(key))].Name, Hash_Table[hash_function(atoi(key))].Stock);
	}	

	

}


/*************************************************************************/


//PROCESS ORDER FUNCTION
//Returns 1; if not enough money(reject)
//Returns 0; If enough money then checkout customer
int process_order(FILE *out,char *grocery_list, float *total, float *wallet, Items_t Hash_Table[MAX_HASH]){
	
	char end_comma[] = ",";															//Fors parsing: stops at comma
	char end_bracket[] = "}";														//Fors parsing: stops at bracket
	char end_list[] = "\n";															//Fors parsing: stops at newline

	
	int g_index = 1;																		//Index is at the first digit of key
	int k_index;																				//For parsing: key string index
	int a_index;																				//For parsing: amount string index

	char key[10];																				//Key string
	char amount[5];																			//Amount string

	
	//Processing Grocery List & Total
	while(grocery_list[g_index] != end_list[0]){				//While grocery list doesnt end

		k_index = 0;																			//Restting Key index to zero for item
		a_index = 0;																			//Restting amount index to zero for item

		memset(amount, 0, sizeof amount);									//Kinda of emptying string: amount
		memset(key, 0, sizeof key);												//Kinda of emptying string: key


		while(grocery_list[g_index] != end_comma[0]){
			key[k_index] = grocery_list[g_index];						//Getting Key string from list
			g_index++;
			k_index++;
		}																									

		g_index += 2;																			//Index is now at the first digit of amount
		while(grocery_list[g_index] != end_bracket[0]){
			amount[a_index] = grocery_list[g_index];				//Getting Amount string from list
			g_index++;	
			a_index++;
		}


		g_index += 1;																			//Index is now at comma OR "\n"
		if(grocery_list[g_index] == end_comma[0]){				//If current index is comma
			g_index += 3;																		//Increase index for next grocery item
		}		
	
		*total += (Hash_Table[hash_function(atoi(key))].Price) * (atoi(amount)); //Adding to total

		//Writing log: Grocery List Order
		fprintf(out, "\n%s x%d @ $%.2f", Hash_Table[hash_function(atoi(key))].Name, atoi(amount), Hash_Table[hash_function(atoi(key))].Price);
	}



	if(*total > *wallet){															//If they don't have enough money
		return 1;																				//Return 1; Reject customer
	}else{		
		
		deduct_inventory(grocery_list, Hash_Table);			//Deducts items from inventory; prints restock 																		
		return 0;																				//Return 0; Checkout customer
	}


}



/*************************************************************************/


//PROCESS CUSTOMERS FUNCTION:
//
void process_customers(char *filename, Customers_t Customer_queue[], Items_t Hash_Table[MAX_HASH], int queue_size){

	char stop[] = ".";																						//Use for parsing filename
	char receipt[30];																							//Receipt string to hold name
	memset(receipt, 0, sizeof receipt);														//Kinda of emptying string receipt

	int parse_index =0;	
	while(filename[parse_index] != stop[0]){	
		receipt[parse_index] = filename[parse_index];								//Copying filename to receipt
		parse_index++;																							//NOT includeing ".txt"
	}	
	strcat(receipt, "_receipt.txt");															//String Cat "_receipt.txt" to receipt str

	


	FILE *out_fp;
  out_fp = fopen(receipt, "w");																	//Opening Receipt file to write to

	float total;																									//Running total of grocery list
	int flag;																											//1 if NOT enough money; 0 for enough


	int Front = 0;																								//Front of array queue
	int Rear = queue_size;																				//Rear of array queue

	//Process each individual customer
	while(Front != Rear){																					//If Front == Rear; queue is empty
		total = 0.00;	
		/*																													//Resetting running total to zero
		printf("\nCustomer Queue [%d] = ", Front);
		printf("\n\tName:  %s", Customer_queue[Front].Name);
		printf("\n\tCash: %f", Customer_queue[Front].Cash);
		printf("\n\tG_List: %s\n", Customer_queue[Front].Grocery_List);
		*/

		fprintf(out_fp, "\nCustomer - %s\n\n", Customer_queue[Front].Name);	//Writing log; Customer Name

		flag = process_order(out_fp,Customer_queue[Front].Grocery_List, &total, &Customer_queue[Front].Cash, Hash_Table);


		if(flag == 0){																						//If 0; chekout customer
			fprintf(out_fp, "\n\nTotal: $%.2f", total);
			fprintf(out_fp, "\nThank you, come back soon!");
			fprintf(out_fp, "\n-------------------------------------------------------\n");
		}else if(flag == 1){																			//If 1; reject customer
			fprintf(out_fp, "\n\nTotal: $%.2f", total);
			fprintf(out_fp, "\nCustomer did not have enough moeny and was REJECTED");
			fprintf(out_fp, "\nThank you, come back soon!");
			fprintf(out_fp, "\n-------------------------------------------------------\n");
		}else{
			//printf(out_fp,"\n......Error occur.....\n");
		}



		Front++;																										
	}

	fclose(out_fp);
	
}


/*************************************************************************/

//OPTION SELECTED FUNCTION:
//Returns int version of the option selected
int option_select(char *option){
	//printf("\nOption: %s", option);

	if(strcmp("checkout", option) == 0){
		return 1;
	}else if(strcmp("inventory", option) == 0){
		return 2;
	}else if(strcmp("quit", option) == 0){
		return 3;
	}else if(strcmp("help", option) == 0){
		return 4;
	}else{
		return -1;
	}

}


/*************************************************************************/


//MENU SYSTEM FUNCTION:
void menu(Items_t Hash_Table[MAX_HASH]){
	printf("\n----------------------------------");
	printf("\n- Welcome To Gabe's Menu System! -\n");
	printf("----------------------------------\n\n");
	


	int flag = 0;																								//Exits Menu if equal to 1; Used for debugging
	

	printf("\n\n---------------------------------------\n");
	printf("- Main Menu includes:                 -\n");
	printf("-                                     -\n");
	printf("-\t* Check-Out Queue of Customers    -\n");	
	printf("-\t* Manage Inventory                -\n");
	printf("-\t* Close Program                   -\n");
	printf("---------------------------------------\n");

	while(flag != 1){

		
		char input_str[300];
		memset(input_str, 0, sizeof input_str);
		printf("\n\n\n:::Enter Command or type \"> help\": \n\n");
		fgets(input_str, 300, stdin);															//Gets Inputted Command string


		char option[35];																					//Option string holds option command
		memset(option, 0, sizeof option);													//Kinda of emptying string: "option"
		

		int index = 2;																						//Index is now at the first letter of command
		int option_index = 0;																			//Index for the string: option
		char stop[] = " ";																				//Use to stop parsing at space
		char stop2[] = "\n";																			//Use to stop parsing at newline
		char letter_c[] = "c";																		//Use to quickly check if input is: "checkout"




		if(input_str[2] == letter_c[0]){														//If Input first letter is c; its (likely) checkout 
			while(input_str[index] != stop[0]){												//Stops at space character
				option[option_index] = input_str[index];								//Getting option from inputted command string
				option_index++;
				index++;
			}	option[option_index] = '\0';														//Adding null terminating character 
		}else{																											//else its: inventory, quit,help, or invalid
			while(input_str[index] != stop2[0]){											//Stops at newline character
				option[option_index] = input_str[index];								//Getting option from inputted command string
				option_index++;
				index++;
			} option[option_index] = '\0';														//Adding null terminating character 
		}
		
	


		//Switch menu options
		switch(option_select(option)){
			case checkout:
				//printf("\nOption selected: checkout\n");
				checkout_customers(input_str, Hash_Table);						//Checkout Customer
				warning_restock(Hash_Table);													//Print restock message if needed
				
				//flag = 1;
				break;

			case inventory:
				//printf("\nOption selected: inventory\n");
				inventory_submenu(Hash_Table);												//Open Inventory submenu
				
				break;

			case quit:
				//printf("\nOption selected: quit\n");
				close_program(Hash_Table);
			
				flag = 1;
				break;

			case help:
				//printf("\nOption selected: help\n");
				help_commands();

				break;

			default:
				printf("\n::::   Invalid input: ");
				printf("\n:::: \"%s\"", input_str);
				printf("\nType \"> help\" for Main Menu syntax\n\n");

				break;
		}
		
	}
	
}



/*************************************************************************/


//CHECKOUT CUSTOMER FUNCTION:
//
void checkout_customers(char *input_str, Items_t Hash_Table[MAX_HASH]){
	

	int index = 11;																									//Index is at the first letter of filename
	int filename_index = 0;								
	char stop[] = "\n";																							//Stops at newline character

  char filename[100];																							//String to hold filename
	memset(filename, 100, sizeof filename);													//Kinda of emptying string: filename

	while(input_str[index] != stop[0]){
		filename[filename_index] = input_str[index];									//Getting filename from input string
		filename_index++;
		index++;
	}
	filename[filename_index] = '\0';																//Adding Null terminating character



	int queue_size = size_of_queue(filename);												//Getting Queue size to make Queue
	//printf("\nsize of queue/customers to enter: %d\n", queue_size);




	if(queue_size > 0){																						//If queue has customers; make queue
		printf("\n\n\t[Customer queue emptied...]\n\t[Receipt txt file created..]\n");
		Customers_t Customer_queue[queue_size];											//Makes Array of customers structs; 
		fill_customer_queue(filename, Customer_queue, queue_size);	//Fills queue array with data from filename
		process_customers(filename, Customer_queue, Hash_Table, queue_size);	//Process the order/Customer


		/*
		int queue_index = 0;

		while(queue_index < queue_size){
		printf("\nCustomer Queue [%d] = ", queue_index);
		printf("\n\tName:  %s", Customer_queue[queue_index].Name);
		printf("\n\tCash: %f", Customer_queue[queue_index].Cash);
		printf("\n\tG_List: %s\n", Customer_queue[queue_index].Grocery_List);
		queue_index++;
	}
		*/	

	}else{
		printf("\n:::: Returning to Main Menu...\n");						//If no customer; or no file...Return to Menu
	}

}



/*************************************************************************/


//RESTOCK ALL ITEMS FUNCTION
void restock_all(Items_t Hash_Table[MAX_HASH]){
	for(int i = 0; i < MAX_HASH; i++){									  				//Check if stock < threshold
		if(Hash_Table[i].Key == -1){																//Checks if struct is empty
			// Struct is empty; Do nothing 
		}else if( Hash_Table[i].Stock < Hash_Table[i].Threshold ){	
			while( Hash_Table[i].Stock < Hash_Table[i].Threshold){
				Hash_Table[i].Stock++;
			}
			printf("\n\t\"%s\" stock back to threshold %d", Hash_Table[i].Name, Hash_Table[i].Stock);
		}
	}
}		


/*************************************************************************/



//IVENTORY SUBMENU FUNCTION
//Has Submenu; and Performs every function/command

void inventory_submenu(Items_t Hash_Table[MAX_HASH]){

	int flag = 0;																		//Flag to go to Main Menu: if 1 exit submenu



	printf("\n\n---------------------------------------\n");
	printf(" Inventory SubMenu includes:\n");
	printf("\n");
	printf("\t>add item (syntax: add key name threshold stock price)\n");	
	printf("\t>delete item (syntax: delete key)\n");
	printf("\t>restock item (syntax: restock key amount\n");
	printf("\t>restock all (syntax: restock all\n");
	printf("\t>return to main menu (syntax: return)\n");
	printf("\n\tEXAMPLES:\n\t  > add 002 \"Limes\" 5 10 3.00\n");
	printf("\t  > delete 101\n");
	printf("\t  > restock 101 5\n");
	printf("\t  > restock all\n");
	printf("\t  > return\n");
	printf("---------------------------------------\n");







	while(flag != 1){

		char input_string[300];
		printf("\n\n:::Enter SUBMENU Command: \n\n> ");
		fgets(input_string, 300, stdin);															//Gets Inputted string


		char stop_space[] = " ";																	//Used for parsing; stops at space
		char stop_nline[] = "\n";																	//Used for parsing; stops at "\n"
		char stop_quotes[] = "\"";																//Used for parsing; stops at quote


		char command[50]; 																				//Holds command string; add, delete, etc...
		memset(command, 0, sizeof command);												//Kinda of emptying string

		int index = 0;																						//Index for the input string
		int p_index = 0;																					//Index for command string; parsing


		if(input_string[6] == stop_nline[0]){											//If Input string[6] is "\n"; (likely) return
			while(input_string[index] != stop_nline[0]){
				command[p_index] = input_string[index];								//Getting command string
				p_index++;
				index++;
			}command[p_index] = '\0';																//Adding null terminater character
		}else{																										//Else get command till first space
			
			while(input_string[index] != stop_space[0]){						//Getting command string
				command[p_index] = input_string[index];
				p_index++;
				index++;
			}command[p_index] = '\0';																//Adding null terminater character
		}



		




		
		if(strcmp(command, "add") == 0){												//COMMAND : ADD
			//printf("\nSelected add");
			
			char add_str[50];																			//Holds the add string data
			memset(add_str, 0, sizeof add_str);										//Kinda of emptying string

			int add_i = 0;																				//Add Data string index
			index += 1;																						//Index is now at the first character after "add"

			while(input_string[index] != stop_nline[0]){			
				add_str[add_i] = input_string[index];								//Getting add data
				index++;
				add_i++;
			} add_str[add_i] = '\n';															//Adding new line character

			char key[10];																					//Holds key string
			char name[50];																				//Holds name string
			char threshold[10];																		//Holds threshold string
			char stock[10];																				//Holds stock string
			char price[10];																				//Holds price string

			memset(key, 0, sizeof key);														//Kinda of emptying strings
			memset(name, 0, sizeof name);
			memset(threshold, 0, sizeof threshold);
			memset(stock, 0, sizeof stock);
			memset(price, 0, sizeof price);




			add_i = 0;																						//Resetting parse index to zero
			index = 0;																						//Index @ first digit of key
			while(add_str[index] != stop_space[0]){								///Stop at space character
				key[add_i] = add_str[index];												//Getting key string
				add_i++;
				index++;
			}

		

			add_i = 0;																					//Resetting parse index to zero
			index += 2;																					//Index @ first letter of name
			while(add_str[index] != stop_quotes[0]){						//Stop at quotes character
				name[add_i] = add_str[index];											//Getting name string
				add_i++;
				index++;
			}
		
			add_i = 0;																					//Resetting parse index to zero
			index += 2;																					//Index @ first digit of threshold
			while(add_str[index] != stop_space[0]){							//Stop at space character
				threshold[add_i] = add_str[index];								//Getting threshold string
				add_i++;
				index++;
			}


			add_i = 0;																					//Resetting parse index to zero
			index += 1;																					//Index @ first digit of stock
			while(add_str[index] != stop_space[0]){							//Stop at space character
				stock[add_i] = add_str[index];										//Getting stock string
				add_i++;
				index++;
			}


			add_i = 0;																					//Resetting parse index to zero
			index += 1;																					//Index @ first digit of price
			while(add_str[index] != stop_nline[0]){							//Stop at new line character
				price[add_i] = add_str[index];										//Getting price string
				add_i++;
				index++;
			}


			if(Hash_Table[hash_function(atoi(key))].Key == -1){
			
				//Struct is empty; so add data
				Hash_Table[hash_function(atoi(key))].Key = atoi(key);
				Hash_Table[hash_function(atoi(key))].Threshold = atoi(threshold);
				Hash_Table[hash_function(atoi(key))].Stock = atoi(stock);
				Hash_Table[hash_function(atoi(key))].Price = atof(price);
				strcpy(Hash_Table[hash_function(atoi(key))].Name, name);
				printf("\n\t[COMPLETE: Item added...]");
			}else{
				printf("\n\t[ERROR: Item key \"%s\" is already taken...]", key);
			}










		}else if(strcmp(command, "delete") == 0){									//COMMAND : DELETE
			//printf("\nSelected delete");

			char key_str[10];																				//Holds key string					
			memset(key_str, 0, sizeof key_str);											//Kinda of emmptying string

			int key_i = 0;																					//Key string index for parsing
			index += 1;																							//Index is now at the first digit of delete
			while(input_string[index] != stop_nline[0]){						//While not encountering "\n" character
				key_str[key_i] = input_string[index];									//Get key
				index++;
				key_i++;
			} key_str[key_i] = '\0';																//Adding null terminator character

			if(Hash_Table[hash_function(atoi(key_str))].Key == -1){
				printf("\n\t[Item doesn't exist]");
			}else{
				//Deleting Item Struct (Resetting)
				printf("\n\t[Item Data Deleted...]");
				Hash_Table[hash_function(atoi(key_str))].Key = -1;
				Hash_Table[hash_function(atoi(key_str))].Stock = -1;
				Hash_Table[hash_function(atoi(key_str))].Threshold = -1;
				Hash_Table[hash_function(atoi(key_str))].Price = -1;
				strcpy(Hash_Table[hash_function(atoi(key_str))].Name, "");
			}
			







			
		}else if(strcmp(command, "restock") == 0){								//COMMAND : ADD
			//printf("\nSelected restock");

			char key_or_all[30];																		//Holds key or all string					
			memset(key_or_all, 0, sizeof key_or_all);								//Kinda of emmptying string
																										
			int p_i = 0;																						// string index for parsing
			index += 1;																							//Index is now at the first character after restock
		

			
			while(input_string[index] != stop_nline[0]){						//Copying input string after "restock"
				key_or_all[p_i] = input_string[index];								//Not includeing "\n"
				index++;
				p_i++;
			} key_or_all[p_i] = stop_nline[0];											//Adding new Line character
			//printf("\nKey_or_all: %s", key_or_all);
							
			
			if(strcmp(key_or_all, "all\n") == 0){										//IF all; Then restock all
				printf("\n\t[Restocking all items under threshold...]");
				restock_all(Hash_Table);
				printf("\n\t[Restocking Complete...]");
			}else{
				index = 0;																						//Index used for parsing

				char restock_key[10];																	//Holds Key string	
				char restock_amount[10];															//Holds Amount string

				memset(restock_key, 0, sizeof restock_key);						//Kinda of emptying string
				memset(restock_amount, 0, sizeof restock_amount);			//Kinda of emptying string

			
				while(key_or_all[index] != stop_space[0]){
					restock_key[index] = key_or_all[index];							//Getting Key string
					index++;
				}

				index += 1;																						//Index is now at the first digit of amount
				p_i = 0;																							//Restting parse index to zero
				while(key_or_all[index] != stop_nline[0]){						//Getting amount string
					restock_amount[p_i] = key_or_all[index];
					index++;
					p_i++;
				}
				

				if(Hash_Table[hash_function(atoi(restock_key))].Key == -1){
					printf("\n\t[Item doesn't exist, Check input]");
				}else{
					//printf("\n\"%s\" stock %d; theshold %d",Hash_Table[hash_function(atoi(restock_key))].Name, Hash_Table[hash_function(atoi(restock_key))].Stock,Hash_Table[hash_function(atoi(restock_key))].Threshold);
					Hash_Table[hash_function(atoi(restock_key))].Stock += atoi(restock_amount);
					printf("\n\t[Restock complete...]");
					//printf("\nAdding %d",atoi(restock_amount));
					//printf("\n\"%s\" stock %d; theshold %d",Hash_Table[hash_function(atoi(restock_key))].Name, Hash_Table[hash_function(atoi(restock_key))].Stock,Hash_Table[hash_function(atoi(restock_key))].Threshold);
				}
				
			}

			
		
			




			

		}else if(strcmp(command, "return") == 0){								//COMMAND : RETURN
			printf("\n>>>> Returning to Main Menu...\n");
			printf("\n\n---------------------------------------\n");
			printf("- Main Menu includes:                 -\n");
			printf("-                                     -\n");
			printf("-\t* Check-Out Queue of Customers    -\n");	
			printf("-\t* Manage Inventory                -\n");
			printf("-\t* Close Program                   -\n");
			printf("---------------------------------------\n");

			flag = 1;
		}else{
			printf("\n:::: Invalid SUBMENU Command ::::\n");
		}
	}
}







/*************************************************************************/


//CLOSE PROGRAM FUNCTION
//Writes current inventory to "inventory.txt" file
//Basically overwrites with new inventory; exact format
void close_program(Items_t Hash_Table[MAX_HASH]){
	FILE *newFP;
	newFP = fopen("inventory.txt", "w");


	printf("\n\t[Writing current Inventory to \"inventory.txt\"...]");

	for(int i = 0; i < MAX_HASH; i++){									  //Go through all Items struct in HASH TABLE
		if(Hash_Table[i].Key == -1){												//Checks if struct is empty
			/* Struct is empty; Do nothing */
		}else{	
			fprintf(newFP, "{%d, \"%s\", %d, %d, %.2f}\n", Hash_Table[i].Key, Hash_Table[i].Name, Hash_Table[i].Threshold, Hash_Table[i].Stock, Hash_Table[i].Price);
		}
	}

	printf("\n\t[Complete: program closing...]\n");


	fclose(newFP);
}





/*************************************************************************/


//HELP COMMAND SYNTAX FUNCTION

void help_commands(){

		printf("\nMAIN MENU COMMANDS:");
		printf("\n\t\"> checkout filename.txt\"");
		printf("\n\t\"> inventory\"");
		printf("\n\t\"> quit\"\n");
}