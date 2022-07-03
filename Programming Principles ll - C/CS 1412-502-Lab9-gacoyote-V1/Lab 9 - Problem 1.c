// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab9_Problem 1.c
// SPECIFICATION:       Write a function to scan and stor information into a structure variable; use for Grocery stores
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)

#include <stdio.h>



//FUNCTIONS PROTOTYPES
void output(); //Prints infomartin entered, "data line", to console
void driver(); //Called in MAIN FUNCTION, the driver functions calls other functions





//STRUCTURES to hold additional data for each Product Category
typedef struct {
  char meat_type;
  char package_date[30];
  char expiration_date[30];
} Meats_t;


typedef struct {
  char type;
  char date_received[30];
} Produce_t;


typedef struct {
  char expiration_date[30];
} Dairy_t;


typedef struct {
  char expiration_date[30];
  int aisle_number;
  char aisle_side;
} CannedGoods_t;


typedef struct {
  char category;
  int aisle_num;
  char aisle_side;
} Nonfoods_t;

//"GROCERY STORE" STRUCTURE
typedef struct {
  char name[20];
  int cost;
  char prod_cat;

  //Product Category Structures
  Meats_t meats;
  Produce_t produce;
  Dairy_t dairy;
  CannedGoods_t cannedgoods;
  Nonfoods_t nonfoods;

} Grocery_t;








//MAIN FUNCTION
int main(void) {


  driver();//driver function calling other functions

  return 0;
}






// NAME:              scan_store()
// INPUT PARAMETERS:  NO Inputs
// OUTPUT:            Returns a structure variable.Prints to the console, and scans input. 
// PURPOSE:          This function asks the user user to enter data to fill into the product/item structure variables.  

Grocery_t scan_store(){

  Grocery_t product;

  printf("Enter Item Name: ");
  scanf(" %[^\n]", product.name);
  printf("Enter Item Cost in Cents: ");
  scanf(" %d", &product.cost);
  printf("Enter Product Category ('M' for meat, 'P' for produce, 'D' for dairy, 'C' for canned goods, 'N' for nonfoods): ");
  scanf(" %c", &product.prod_cat);

  //Switch case to ask specific questions based off product category
  switch (product.prod_cat){
    case 'M':
    case 'm':
      printf("\nEnter the meat type ('R' for red meat, 'P' for poultry, 'F' for fish): ");
      scanf(" %c", &product.meats.meat_type);
      printf("Enter Packaging Date: ");
      scanf(" %[^\n]", product.meats.package_date);
      printf("Enter the expiration date: ");
      scanf(" %[^\n]", product.meats.expiration_date);
      break;

    case 'P':
    case 'p':
      printf("\nEnter character type ('F' for fruit, 'V' for vegetable): ");
      scanf(" %c", &product.produce.type);
      printf("Enter the date recieved: ");
      scanf(" %[^\n]", product.produce.date_received);
      break;

    case 'D':
    case 'd':
      printf("\nEnter expiration date: ");
      scanf(" %[^\n]", product.dairy.expiration_date);
      break;

    case 'C':
    case 'c':
      printf("\nEnter expiration date (month and year only):");
      scanf(" %[^\n]", product.cannedgoods.expiration_date);
      printf("Enter the aisle number:");
      scanf(" %d", &product.cannedgoods.aisle_number);
      printf("Enter the aisle side (letter 'A' or 'B'): ");
      scanf(" %c", &product.cannedgoods.aisle_side);
      break;

    case 'N':
    case 'n':
      printf("\nEnter the character indicating category ('C' for cleaning product, 'P' for pharmacy, 'O' for other): ");
      scanf(" %c", &product.nonfoods.category);
      printf("Enter the aisle number: ");
      scanf(" %d", &product.nonfoods.aisle_num);
      printf("Enter the aisle side (letter 'A' or 'B'): ");
      scanf(" %c", &product.nonfoods.aisle_side);
      break;

    default:
      printf("\nInvalid product category!");
      break;

  }
  return product;
}







// NAME:              output
// INPUT PARAMETERS:  A structure variable; 'product'
// OUTPUT:            No Returns; Prints to the console the information entered by the user in a formatted "data line"
// PURPOSE:           This function is use to format the information entered base on the product category, it then prints the information formatted, "data line", to the console

void output(Grocery_t product){

  printf("\n\n\n"); //for readablility I printed excess line space
  printf("The data line for the item you enter is: \n\n");
  switch(product.prod_cat){
    case 'M':
    case 'm': 
    printf("%s %d%c %c %s %s", product.name, product.cost,product.prod_cat, product.meats.meat_type, product.meats.package_date, product.meats.expiration_date);

      break;

    case 'P':
    case 'p':
      printf("%s %d%c %c %s", product.name, product.cost,product.prod_cat, product.produce.type, product.produce.date_received);

      break;

    case 'D':
    case 'd':
      printf("%s %d%c %s", product.name, product.cost,product.prod_cat,product.dairy.expiration_date);

      break;

    case 'C':
    case 'c':
      printf("%s %d%c %s %d%c", product.name, product.cost,product.prod_cat,product.cannedgoods.expiration_date, product.cannedgoods.aisle_number,product.cannedgoods.aisle_side);

      break;

    case 'N':
    case 'n':
      printf("%s %d%c %c %d%c", product.name, product.cost,product.prod_cat,product.nonfoods.category, product.nonfoods.aisle_num, product.nonfoods.aisle_side);

      break;

    default:
      break;

  }
}







// NAME:              driver
// INPUT PARAMETERS:  NO inputs
// OUTPUT:            No output/returns; but does print to console & scans from it.
// PURPOSE:           The driver console calls other function to execute them, the driver function itself is called within the 'main' function.

void driver(){
  Grocery_t item;
  item = scan_store();
  output(item);
}