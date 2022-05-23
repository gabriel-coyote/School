#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10000


//STRUCTURE: Customer
//PURPOSE: Creating Binary search Tree
typedef struct Customer_node{
	int ID;												
	char Name[MAXSIZE];
	float Store_Balance;
	struct Customer_node *left;
	struct Customer_node *right;
} Customer_t;





//FUNCTION:		Creates Nodes FROM starter file "customers.txt"
//PURPOSE:		Crates node from txt file, AND returns the node
Customer_t* createNode(char *data_STR){
	Customer_t* new_node = (Customer_t*)malloc(sizeof(struct Customer_node));	//Allocates memory for new node

	//EXAMPLE OF A DATA STR
	//{1688, "Karen", 65.00}
	int index=0;
	index += 1; 											//Accounts for the initial [ { ] bracket


	char ID_str[4];
	float ID_float;

	//ID is 4 Numbers
	for(int k = 0; k < 4; k++){		
		ID_str[k] = data_STR[index];
		index++;
	}
	
	ID_float = atof(ID_str);							//Type casting str to float
	new_node->ID = (int)ID_float; 							//type casting float to int: Assigning ID to New_node



	index += 3; 													//Accounts for the [ ,(space)" ] in data_STR
	//Index is now at the first characther of Name, in data_STR



	char end[] = "\"";										//char character "
	int node_index = 0;

	while(data_STR[index] != end[0]){ 		//While character doesn't equal quatation mark
		new_node->Name[node_index] = data_STR[index]; //Copying name to New_node
		node_index++;
		index++;
	}
 //printf("NODE CREATED NAME = %s\n", new_node->Name);

	index += 3; //Accounts for the [ ",(space) ] in data_STR
	//Index is now at the first starting int, in data_STR



	char store_balance_str[1000];
	float store_balance_float;

	char END[] = "}"; //Officialy end of data_STR
	int balance_index = 0;

	while(data_STR[index] != END[0]){ //While Character doesn't equal ending bracket '}'
		store_balance_str[balance_index] = data_STR[index]; //Copying number to string store balance_index
		balance_index ++;
		index++;
	}

	store_balance_float = atof(store_balance_str);	//type casting str to float
	new_node->Store_Balance = store_balance_float;	//Assign Store Balance to New_node


	new_node->left = NULL;
	new_node->right = NULL;

	//printf("NODE CREATED %d : %s : %f\n", new_node->ID, new_node->Name, new_node->Store_Balance);
	return new_node;
}


//FUNCTITON:			Inserts nodes into BST, Recursively
//PURPOSE:				Insert nodes into Binary search tree; 
void insert(Customer_t **tree, int ID, char* data_str){
	
	if(*tree == NULL){											//Coule be either left or right 
		//printf("\nAssiging node to this location\n");
		*tree = createNode(data_str);
	} else if(ID < (*tree)->ID){ 						//If ID is less than
		//printf("\n\t %d < %d Going left", ID, (*tree)->ID);
		insert(&(*tree)->left, ID, data_str);				//Insert to left
	} else if(ID > (*tree)->ID){	
	//	printf("\n\t %d > %d Going right", ID, (*tree)->ID);
		insert(&(*tree)->right, ID, data_str); 			//Else if ID is greater; insert right
	} else{
		printf("\nERROR; ID might have already been used"); //ID might be equal; meaning ID is already used
	}
}


//FUNCTITON:		Creates Initial BST from customers.txt 
//PURPOSE:			Makes binary searh tree 
Customer_t* BST(char *data_str, Customer_t *root){
	
	//If list is empty make beginning node to assign as root
	if(root == NULL){
	//	printf("Creating root str: %s", data_str);
		Customer_t* new_node = createNode(data_str);
		root = new_node;
		return root;
	}
	//printf("\n\nInserting str: %s", data_str);



	char ID_str[4];
	float ID_float;
	int index = 1;

	//ID is 4 Numbers
	for(int k = 0; k < 4; k++){		
		ID_str[k] = data_str[index];
		index++;
	}
	
	ID_float = atof(ID_str);
	int ID = (int)ID_float;
	//printf("ID = %d", ID);

	insert(&root, ID, data_str); //Insert node into BST


	return root;
}



//FUNCTIONS:			Pre-In-Post ORDER functions to print BST to Txt File
//PURPOSE:
void pre_order(Customer_t *tree, FILE *fp){
	if(tree !=  NULL){
		fprintf(fp,"\n{%04d, \"%s\", %.2f}", tree->ID, tree->Name, tree->Store_Balance);
		pre_order(tree->left, fp);
		pre_order(tree->right, fp);
	}
}
void in_order(Customer_t *tree, FILE *fp){
	if(tree !=  NULL){
		in_order(tree->left, fp);
		fprintf(fp,"\n{%04d, \"%s\", %.2f}", tree->ID, tree->Name, tree->Store_Balance);
		in_order(tree->right, fp);
	}
}
void post_order(Customer_t *tree, FILE *fp){
	if(tree !=  NULL){
		post_order(tree->left, fp);
		post_order(tree->right, fp);
		fprintf(fp,"\n{%04d, \"%s\", %.2f}", tree->ID,tree->Name, tree->Store_Balance);
	}
}


//FUNCTIONS:			Adds to Binary search tree from User Input
//PURPOSE:			Used/called within switch menu
void add(Customer_t** tree, int ID, char* Name, float Balance){
	if(*tree == NULL){
		*tree = (Customer_t*)malloc(sizeof(struct Customer_node));
		(*tree)->ID = ID;
		strcpy((*tree)->Name, Name);
		(*tree)->Store_Balance = Balance;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}else if(ID < (*tree)->ID){ 						//If ID is less than
	//	printf("\n\t %d < %d Going left", ID, (*tree)->ID);
		add(&(*tree)->left, ID, Name, Balance);				//Insert to left
	} else if(ID > (*tree)->ID){	
		//printf("\n\t %d > %d Going right", ID, (*tree)->ID);
		add(&(*tree)->right, ID, Name, Balance); 			//Else if ID is greater; insert right
	} else{
		printf("\n[ERROR] ID might have already been used"); //ID might be equal; meaning ID is already used
	}
}


//FUNCTIONS:			Returns Min value in tree
//PURPOSE:			Used/called within Delete
Customer_t* min_value_node(Customer_t *tree){
	Customer_t* current = tree;

	while(current && current->left != NULL){
		current = current->left;
	}

	return current;
}

//FUNCTIONS:			Delters from Binary search tree from User Input; returns new root
//PURPOSE:			Used/called within switch menu
Customer_t* delete(Customer_t* tree, int ID){
	if(tree == NULL){
		return tree;
	}
	if (ID < tree->ID){									
		tree->left = delete(tree->left, ID);
	} else if(ID > tree->ID){
		tree->right = delete((tree)->right, ID);
	} else{
		//Node with one or no child
		if(tree->left == NULL){						
			Customer_t* temp = tree->right;
			free(tree);
			return temp;
		} else if(tree->right == NULL){
			Customer_t* temp = tree->left;
			free(tree);
			return temp;
		}

		//Node with 2 kids
		Customer_t* temp = min_value_node(tree->right);

		//Copying content to this node
		tree->ID = temp->ID;

		//Deleting inorder succcesor
		tree->right = delete(tree->right, tree->ID);

	}

	return tree;
}


//FUNCTIONS:			Search for Person from ORDERS in BST
//PURPOSE:			Used/called within process_orders functions
Customer_t* search(Customer_t* root, int ID){
	if(root == NULL || root->ID == ID){ 	//Base case: Root is null, or ID is present at this position
		return root;
	}

	if(root->ID < ID){
		return search(root->right, ID);
	}else {
		return search(root->left, ID);
	}
}

//FUNCTIONS:			Process Customer Orders from txt file inputted; prints action
//PURPOSE:			Used/called within switch menu
void process_orders(Customer_t* tree, char *FileName){

	FILE* fp;
	fp = fopen(FileName,"r");

	printf("\n\n::::File %s processing...\n", FileName);


	
	char str[MAXSIZE];
	char end[] = "}";


	//Process orders in While loop
	while(fgets(str, MAXSIZE, fp) != NULL){
		char ID_str[5];
		int ID_int;
		char order_str[1000];
		float order_float;

		//printf("\norder: %s", str);	
		//Copys ID num to str
		for(int k = 0; k < 4; k++){
			ID_str[k] = str[(k+1)];
		}
		ID_int = atof(ID_str);		//Type cast ID-Str to float
		//printf("\nID int : %d", ID_int);



		int i = 7; //Poisition index at first starting number
		int order_i = 0;
		//Copying order to str
		while(str[i] != end[0]){
			order_str[order_i] = str[i];
			order_i++;
			i++;
		}

		order_float = atof(order_str); 	//Type casting Order str to float
		//printf("\nOrder Float: %.2f", order_float);

		

		Customer_t *Customer;
		Customer = search(tree, ID_int); //Finds node with ID

		float Bal; //Amount deducted from the customer's store balance
		float cash;// amount the customer has to pay after exhuasting their store balance

		//Taking in Order; math opertations
		if(Customer == NULL){
			printf("\nCustomer %04d was not found, or deleted, from BST", ID_int);
		} else if((Customer->Store_Balance - order_float) < 0){		//Order exhuast store balance

			Bal = Customer->Store_Balance; //Storing orginal store balance
			cash = -1*(Customer->Store_Balance - order_float); //Amount paid in cash
			Customer->Store_Balance = 0;

			printf("\nCustomer %04d, %s, payed $%.2f from their store balance and $%.2f at the register, $%.2f remaining store balance.", Customer->ID, Customer->Name, Bal, cash, Customer->Store_Balance);

		}else if((Customer->Store_Balance - order_float) > 0){	//Order DID NOT exhuast store balance
			Bal = order_float;
			cash = 0.00;
			Customer->Store_Balance = (Customer->Store_Balance - order_float);


			printf("\nCustomer %04d, %s, payed $%.2f from their store balance and $%.2f at the register, $%.2f remaining store balance.", Customer->ID, Customer->Name, Bal, cash, Customer->Store_Balance);

		} else if((Customer->Store_Balance - order_float) == 0){ //Used ONLY (all of) store balance
			Bal = order_float;
			cash = 0.00;
			Customer->Store_Balance = (Customer->Store_Balance - order_float); //Should be 0

			printf("\nCustomer %04d, %s, payed $%.2f from their store balance and $%.2f at the register, $%.2f remaining store balance.", Customer->ID, Customer->Name, Bal, cash, Customer->Store_Balance);

		}else{
			printf("\n[ERROR] Processing order...\n");
		}

		//printf("\nCustomer %d, %s, payed $.2f from their store balance and $.2f at the register, %.2f remaining store balance.", Customer->ID, Customer->Name, );
	}

	fclose(fp); 
	printf("\n\n::::File %s Closed...\n", FileName);

}









//FUNCTIONS:			MENU infinty while loop with switch
//PURPOSE:			Used/called within Main function
void menu(Customer_t* tree, char *operation, char* filename, int id, char* name, float balance, char *order){
	printf("\nOperations Avaiable: \nInput Corresponding Number");
	printf("\n-------------------------------------");
	printf("\n1.) add ");
	printf("\n2.) delete");
	printf("\n3.) process");
	printf("\n4.) quit");


	int sel = 0;
	

	while(sel != -1){

		printf("\n\n[Menu Select (NUM 1-4)]> ");
		scanf(" %d", &sel);
		printf("\n--------------------------------");

		switch(sel){
			case 1:	//ADD
				printf("\n[Example Input]: add 0002 Billy 61.00\n\n");
				printf("input> ");
				scanf(" %s %d %s %f", operation, &id, name, &balance);

				add(&tree, id, name, balance);
				break;


			case 2:	//Delete
				printf("\n[Example Input]: delete 0001\n\n");
				printf("input> ");
				scanf(" %s %d", operation, &id);

				tree = delete(tree, id);

				break;


			case 3:	//Process
				printf("\n[Example Input]: process orders.txt\n\n");\
				printf("input> ");
				scanf(" %s %s", operation, filename);

				process_orders(tree, filename);


				break;


			case 4:	//Quit
				printf("\n[Example Input]: quit\n\n");
				printf("input> ");
				scanf(" %s", operation);
				printf("\n[Please enter output format]: pre, post, or in order");
				printf("\n\ninput> ");
				scanf(" %s", order);

				FILE *FP;
				FP = fopen("newcustomers.txt", "w");
				if(strcmp(order, "post") == 0){
						printf("\noutput> writing to newcustomers.txt in post-order, shutting down...\n");
						post_order(tree, FP);
				} else if(strcmp(order, "in") == 0 ){
						printf("\noutput> writing to newcustomers.txt in in-order, shutting down...\n");
						in_order(tree, FP);
				}else if(strcmp(order, "pre") == 0){
						printf("\noutput> writing to newcustomers.txt in pre-order, shutting down...\n");
						pre_order(tree, FP);
				}else{
					printf("\nInvalid Input: Re-RUN Program\n");
				}

				fclose(FP);

				sel = -1;
				break;


			default:
				printf("\nInvalid Selection: Enter Number 1-4\nRe-Run Program\n");
				exit(0);
				break;
		}
	}

}
















//MAIN FUNCTION
int main(void) {

	Customer_t *root = NULL;


	FILE *fp;
	char* filename = "customers.txt"; 				//Not Inputed: Always open this text filename
	fp = fopen(filename, "r"); 								//Open file to read
	if(fp == NULL){														// Checks if file exists
		printf("\nCould not open file %s", filename);
		return (1);
	}else{
		printf("\nOpening File: %s\n", filename);
	}

	//Gets each line of txt file as a string to process/create node
	char str[MAXSIZE];

	printf("Creating BST from %s ...\n", filename);
	while(fgets(str, MAXSIZE, fp) != NULL){
		//printf("\nstr = %s",str);
		root = BST(str, root);									//Creates starting Binary search tree from customers.txt	
	}
	fclose(fp);
	printf("BST created.\nClosing File: customers.txt\n\n");
	

	//Stores value of Input 
	char opertion[10];
	char order[10];
	char Inputted_filename[1000];
	int num;
	char name[100];
	float balance;

	
	menu(root, opertion, Inputted_filename, num, name, balance, order);



	printf("\n------------------------");
	/*
	printf("\n\n\nPrinting PRE order");
	pre_order(root);
	printf("\n\n\nPrinting IN order");
	in_order(root);
	printf("\n\n\nPrinting POST order");
	post_order(root);
	*/
  return 0;
}
