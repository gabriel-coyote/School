// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab1_Problem2.c
// SPECIFICATION:       Given purchase price, down payment, annual interest rate, total number of payments, return the motnhly payment amount, and amount borrowed.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)



#include <stdio.h>
#include <math.h>

//Function Prototypes
void monthly_payment(double PurchasePrice, double DownPayment, double AnnualInterestRate, double TotalNumPayments);

//Declare for future use
double purchase_price, down_payment, annual_interest_rate, total_num_payments;

//MAIN FUNCTION
int main(void){
  printf("Enter the purchase price: \n");
  scanf("%lf",&purchase_price);
  printf("Enter the down payment: \n");
  scanf("%lf",&down_payment);
  printf("Enter the annual interest rate: \n");
  scanf("%lf",&annual_interest_rate);
  printf("Enter the total number of payments: \n");
  scanf("%lf",&total_num_payments);

  monthly_payment(purchase_price,down_payment,(annual_interest_rate/100),total_num_payments);

  return 0;
}







// NAME:              monthly_payment
// INPUT PARAMETERS:  Purchase Price, Down Payment, Annual Interest Rate, Total Number of Payments, as a list of 'doubles'
// OUTPUT:            Prints the amount borrowed, and monthly payment.
// PURPOSE:           The function calculates the monthly payment, and amount borrowed using the given formula
void monthly_payment(double PurchasePrice,double DownPayment,double AnnualInterestRate,double TotalNumPayments){

  printf("**********************************\n\n");

  double principal;
  principal = PurchasePrice-DownPayment;
  printf("The amount borrowed: $%.2lf\n",principal);

  double monthly_interest_rate;
  monthly_interest_rate = AnnualInterestRate/12;


  double a,b,c,d,e,f;   //The letters represents steps for the order of operation for the given formula
  a = monthly_interest_rate*principal;
  b = 1+monthly_interest_rate;
  c = -TotalNumPayments;
  d = pow(b,c);
  e = 1-d;
  f = a/e;
  

  double monthly_payment;
  monthly_payment = f;
  printf("Your monthly payment is: $%.2lf",monthly_payment);


}