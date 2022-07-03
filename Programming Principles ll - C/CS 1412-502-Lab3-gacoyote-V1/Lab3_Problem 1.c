// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab3_Problem1.c
// SPECIFICATION:       Use a switch to compute employee weekly pay, also show total number of employees paid.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)


#include <stdio.h>
#include <stdlib.h>

//Function Prototypes
void weekly_pay(int employee_code);
void paycode_input(void);


//Varaibles to keep track of who, and how many, employees are payed.
// Are used within the switch. 
//Defualt value is zero.
int managers_paid = 0;
int hourly_workers_paid = 0;
int commission_workers_paid = 0;
int pieceworkers_paid = 0;



//MAIN FUNCTION
int main(void) {

  paycode_input();

  printf("Total number of managers paid           : %d\n", managers_paid);
  printf("Total number of hourly workers paid     : %d\n", hourly_workers_paid);
  printf("Total number of commission workers paid : %d\n", commission_workers_paid);
  printf("Total number of piece workers paid      : %d\n", pieceworkers_paid);

  
  return 0;
}








// NAME:              paycode_input
// INPUT PARAMETERS:  No input is require
// OUTPUT:            Prints a statement, declaring user to enter paycode.
// PURPOSE:           The function is used to get paycode inputted by the user, 
//                    then calls on another function to compute weekly pay.
void paycode_input(void){
  int paycode;

  printf("\nEnter paycode ( -1 to end): ");
  scanf("%d", &paycode);

  weekly_pay(paycode);
}














// NAME:              weekly_pay
// INPUT PARAMETERS:  'employee_code' as a INTEGER; paycode number
// OUTPUT:            Prints weekly pay of employee based of inputted information
// PURPOSE:           The function uses a switch, each case calculates weekly pay of a certain employee based of inputted info. 
//                    The weekly pay of said employee is printed out.
void weekly_pay(int employee_code){

  //Varaibles declared for calculating pay.
  float manager_pay;  //case 1
  float hourly_wage;  //case 2
  float total_hr_worked;  //case 2
  float hourly_worker_pay;  //case 2
  float gross_weekly_sales; //case 3
  float commission_pay;   //case 3
  float fixed_amount_pay; //case 4
  float items_produced;  //case 4


  //Switch hase Cases; Each with a function within.
  switch (employee_code) {
    case -1:
      printf("\n");
      break;  //Ends switch if '-1' is entered


    case 1:
      printf("Manager selected.\n");
      printf("Enter weekly salary: ");
      scanf("%f", &manager_pay);
      printf("The manager's pay is $%.2f\n", manager_pay);

      managers_paid = (managers_paid + 1);  //Tracks number of certain worker paid.
      paycode_input();  //Recursion; calls paycode input and goes through switch again.
      break;


    case 2:
      printf("Hourly Worker selected.\n");
      printf("Enter hourly wage: ");
      scanf("%f", &hourly_wage);
      printf("Enter total hours worked: ");
      scanf("%f", &total_hr_worked);

          //Calculates Pay; and adds any overtime pay.
          if (total_hr_worked > 40){
            hourly_worker_pay = (40 * hourly_wage);
            hourly_worker_pay += ((total_hr_worked - 40) * (1.5 * hourly_wage));
          }
          else {
            hourly_worker_pay = hourly_wage * total_hr_worked;
          }

      printf("The hourly worker's pay is: $%.2f\n", hourly_worker_pay);
      
      hourly_workers_paid = (hourly_workers_paid + 1);  //Tracks number of certain worker paid.
      paycode_input();  //Recursion; calls paycode input and goes through switch again.
      break;   
      

    case 3:
      printf("Commision Worker selected.\n");
      printf("Enter gross weekly sales: ");
      scanf("%f", &gross_weekly_sales);
      commission_pay = (250 + (.057 * gross_weekly_sales)); //Calculates pay

      printf("The commission worker's pay is: $%.2f\n", commission_pay);
      
      commission_workers_paid = (commission_workers_paid + 1);  //Tracks number of certain worker paid.
      paycode_input();  //Recursion; calls paycode input and goes through switch again.
      break;


    case 4:
      printf("Pieceworker selected.\n");
      printf("Enter fixed amount of money for each item produced: ");
      scanf("%f", &fixed_amount_pay);
      printf("Enter number of items they produced: ");
      scanf("%f", &items_produced);

      printf("The pieworker worker's pay is: $%.2f\n", (fixed_amount_pay * items_produced));
    
      pieceworkers_paid = (pieceworkers_paid + 1);  //Tracks number of certain worker paid.
      paycode_input();  //Recursion; calls paycode input and goes through switch again.
      break;


    default:  //If an integer is entered that isn't accounted for.
      printf("Invalid pay code\n");

      paycode_input();  //Recursion; calls paycode input and goes through switch again.
      break;

  }


}