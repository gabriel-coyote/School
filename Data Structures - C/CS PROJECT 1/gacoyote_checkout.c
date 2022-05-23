#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10000


//Linked List for Queue: Customer
typedef struct qnode{
	struct Customer *person;
	struct qnode *next;
}qnode;

//FOR LINKED LIST: Grocery_item
typedef struct Grocery_node{
	struct Grocery_item *element;
	struct Grocery_node *next;
} Grocery_node;



 
//STRUCTURE: Grocery_item
typedef struct{
	char Name[MAXSIZE];
	float price;
	int number;
} Grocery_item;


//STRUCTURE: Customer
typedef struct Customer{
	char Name[MAXSIZE];
	float cash;
	char List[MAXSIZE];
	//struct Grocery_node *list;//Pointer to linked list of grocery items
//	struct Customer *next;//Pointer to next customer in Queue
} Customer;













//NOTE TO SELF USE; THIS TO CREAT Queue NODE !!!!!!!!
qnode* create(char *data,qnode *next)
{
    qnode* new_node = (qnode*)malloc(sizeof(struct qnode));
    if(new_node == NULL)
    {
        printf("Can't creat Node : ERROR!!\n");
        exit(0);
    }

		//printf("Name = %s\n", new_node->person->Name);

		//Allocating memory for customer struct in qnode
		new_node->person = (Customer*)malloc(sizeof(Customer));

	
		char end[] = "\"";
		
		int i;//USED TO TRACK INDEX OF DATA STR WHILE PARSING
		int index_tracker = 0;

		//ASIGNING NAME TO CUSTOMER STRUCT
		 for ( i = 2; data[i] != '\0'; i++) {
			 //printf("data[%d]: %c\n",  i, data[i]);
				if(data[i] == end[0]){break;}
				
				 new_node->person->Name[index_tracker] = data[i];
				 index_tracker++;
			 }
			//new_node->person->Name[i] = data[i];
		//	printf("index tracker = %d", index_tracker);
    
		i=	i+2;//TO ACCOUNT FOR ", "
		char start[] = ",";
		char cash[1000];
		float Cash_float;
		int j=0;
		

		while(data[i] != start[0]){
	
			cash[j] = data[i];
			j++;
			i++;
		}
		Cash_float = atof(cash);//Type casting to str cash to float cash
		//printf("cash = %lf", Cash_float);

		new_node->person->cash = Cash_float;//Assinng float cash to stuct customer cash

		//DID NOT FINISH WITH GROCERY ITEM LINKED LIST AND BEYOND
		char item_list[10000];

		int k =0;
		while(data[i] != '\0'){
			i++;
			new_node->person->List[k] = data[i];
			k++;
		}
		//printf("%s", new_node->person->List);

		

    new_node->next = next;
 
    return new_node;
}







//FUNCTION: Appending node to the end of the list
qnode* append(char *data, qnode *head)
{
		//printf("\nappend str: %s\n", data);
		
		//If list is empty make beginning node to assign to head
		if(head == NULL){
			//printf("Head is null\n");
			qnode* new_node = create(data,head);
    	head = new_node;
    	return head;
		}
  
		//if list is not empty; Find the last node
    qnode *cursor = head;
    while(cursor->next != NULL)
        cursor = cursor->next;
 
	//Create node
    qnode* new_node =  create(data,NULL);
    cursor->next = new_node;
 
    return head;
}



//FUNCTION: DEDUEE the front of the linked list qnode
//ALSO WRITES TO FILE "output.txt"
qnode* dequeue_front_outfile(qnode* head, FILE *out)
{
	fprintf(out,"%s had $%.2lf dollars and grocery list of %s", head->person->Name,head->person->cash,head->person->List);
    if(head == NULL)
        return NULL;
    qnode *front = head;
    head = head->next;
    front->next = NULL;
    
    if(front == head)
        head = NULL;
		free(front->person);//FREE STRUCT CUSTOMER
    free(front);//Free memory Qnode struct
    return head;
}






//DISPLAY Customer Queue
void display_list (qnode *head) {
  qnode *ptr = head;           /* set ptr to the first node in the linked list */
  if (ptr == NULL)               /* check for an empty list */
    printf("List is Empty\n");
  else {
    while(ptr != NULL){          /* while we have not encountered the end of the list */
      printf("\nDisplay node NAME: %s", ptr->person->Name);
			printf("\n\t\tnode Cash: %lf", ptr->person->cash); 
			printf("\n\t\tnode List: %s", ptr->person->List);  /* print the list node data */
      ptr = ptr->next;           /* go to the next node in the linked list */
    }
  }
}















//MAIN FUNCTION
int main(void) {
	qnode *head = NULL;//pointer to start of quere
	char null = '\0';


	FILE *fp;
    char str[MAXSIZE];
    char* filename = "input.txt";
		int sum = 0;//SUm is usedd for my own debugging
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXSIZE, fp) != NULL){
			sum++;
			
      printf("\nstr %d : %s\n", sum,str);
			head = append(str, head);
				
		}
    fclose(fp);

	//printf("\n\nstr = %s\nsum = %d\n", str, sum);

	//display_list(head);
FILE *outFP;

outFP = fopen("output.txt","w");
fprintf(outFP,"!!!I did not finish...\n");

	while(head != NULL){

		display_list(head);
		head = dequeue_front_outfile(head, outFP);
		printf("\n\n---Removing front---\n\n");
	}

  fclose(outFP);
	
  return 0;
}
