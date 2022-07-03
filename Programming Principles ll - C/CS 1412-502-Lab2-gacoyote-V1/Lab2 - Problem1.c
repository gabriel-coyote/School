// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab2_Problem1.c
// SPECIFICATION:       Given Purchase Total, whether the user is a teacher, make a program to store the receipt in a .txt file. 
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)


#include <stdio.h>
#include <string.h>


//Function Prototypes
void receipt(float Purchase, char Teacher[]);


//Declare for Future Use
float purchase_total;
char teacher[];
float SALES_TAX = .05;



//MAIN FUNCTION
int main(void) {
  printf("Enter the purchase total: ");
  scanf("%f", &purchase_total);


  printf("\nAre you teacher?\nEnter 'yes' or 'no': ");
  scanf("%s", &teacher);

  receipt(purchase_total, teacher);

  printf("\n\n'receipt.txt' was successfully created.");


  return 0;
}








// NAME:              receipt
// INPUT PARAMETERS:  'Purchase' as a float, 'Teacher' as a char
// OUTPUT:            Prints a receipt in .txt file called 'receipt.txt'
// PURPOSE:           The function applies discount based on user input, then calculates sales tax & total. 
void receipt(float Purchase, char Teacher[]){

  //Stores Teacher discount percentage
  float teacher_discount;


  //Determines Teacher Discount
  if (!strcmp(Teacher, "yes")){
    if (Purchase >= 100.00){
      teacher_discount = .12;
    } else {
      teacher_discount = .10;
    }
  } else{
  }


  //Calculates Teachers's discount amount and Discounted Total
  float teacher_discount_amount = Purchase * teacher_discount;
  float teacher_discounted_total = Purchase - teacher_discount_amount;




  //FILE is a data type
  //File pointer; '*' represents pointer
  // 'receipt' can be whatever name
 FILE *receipt;


  //receipt is a variable
  //Opens/Creates 'receipt.txt' file to write to
  receipt = fopen("receipt.txt","w");


  //Receipt for Teachers
  if (teacher_discount > 0){
    fprintf(receipt,"Total purchases               $ %.2f\n", Purchase);
    fprintf(receipt,"Teacher's discount (%.0f%%)         %.2f\n", teacher_discount * 100, teacher_discount_amount);
    fprintf(receipt,"Discounted total                %.2f\n", teacher_discounted_total);
    fprintf(receipt,"Sales tax (5%%)                    %.2f\n", teacher_discounted_total * SALES_TAX);
    fprintf(receipt,"Total                         $ %.2f\n", teacher_discounted_total + (teacher_discounted_total * SALES_TAX));


  } 
  //Receipt for NON - Teachers
  else{
    fprintf(receipt,"Total purchases              $ %.2f\n", Purchase);
    fprintf(receipt,"Sales Tax (5%%)                  %.2f\n", Purchase * SALES_TAX);
    fprintf(receipt,"Total                        $ %.2f\n", Purchase + (Purchase * SALES_TAX));


  }

  //FunctionPrintF (LookHere, "This Text is Written")
  //fprintf(receipt, "This Text is Written\n");

  //Closes file TO SAVE
  fclose(receipt);
}