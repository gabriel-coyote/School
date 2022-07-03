// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab1_Problem1.c
// SPECIFICATION:       Given a starting and ending odometer reading (numbers), return distance traveld and reimbursement.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)

#include <stdio.h>


//CONSTANT MACRO
#define RATE 0.35

//Function Prototypes
float calc(float start_read, float end_read);


//Declare for future use
float odo_start;        //Odometer beginning reading
float odo_end;          //Odometer ending reading
float distance_traveled;


//MAIN FUNCTION
int main(void) {

  printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
  printf("Enter the beginning odometer reading => ");
  scanf("%f",&odo_start);

  printf("Enter the ending odometer reading => ");
  scanf("%f",&odo_end);

  float distance_travled = calc( odo_start,odo_end);


  printf("You travleved %.1f miles. At $0.35 per mile, your reimbursement is $ %.2f. \n", distance_travled,distance_travled * RATE);



  return 0;
}


// NAME:              calc
// INPUT PARAMETERs:  start_read,end_read, (beginning and ending odometer reading)
// OUTPUT:            RETURNS A float number, the distance travled
// PURPOSE:           The function computes the distance travel given the odometer readings
float calc(float start_read, float end_read) {
return (end_read-start_read);
}
