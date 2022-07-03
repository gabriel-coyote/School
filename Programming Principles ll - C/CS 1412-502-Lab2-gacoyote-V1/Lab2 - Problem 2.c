// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab2_Problem2.c
// SPECIFICATION:       Given initial presence of an ammount in grams calculate & print in table form, the amount of cobalt-60 isotope mass that remains after each year, for 5 years.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)



#include <stdio.h>
#include <math.h>

//Function Prototypes
void half_life_table(float amount);

//Declared for Future Use
// Cobalt-60 has a half life of 5.272 years
float initial_amount;
double COBALT_HALF_LIFE = 5.272;



//MAIN FUNCTION
int main(void) {
  printf("Enter initial presence of Cobalt amount, in grams: ");
  scanf("%f", &initial_amount);

  printf("\n\nInitial Cobalt-60 Amount: %.3f\n", initial_amount);
 
  half_life_table(initial_amount);

  return 0;
}



// NAME:              Half_life_tabel
// INPUT PARAMETERS:  'amount' as a float
// OUTPUT:            Table Form Amount of Isotope left after each year.
// PURPOSE:           The function calculates amount of cobalt-60 isotope is left after each year, for 5 years. In Table Form, using given formula. 

void half_life_table(float amount){

  //Declared for formula
  //Stores Amount_left after each year
  double amount_left;

  //Incremented by 1 each year
  double year = 1;


  //Variable "C" needed for formula
  // C = e^(-0.693)
  double C;
  C = exp(-0.693);


  //Table Formatted
  printf("\n\nYEARS ELAPSED     AMOUNT LEFT (Grams)");
  printf("\n************************************\n");


while (year < 6){


  //Variable "y_h" needed for formula
  // y_h = years elapsed / half-life of the isotope in years
  double y_h;
  y_h = (year/COBALT_HALF_LIFE);

  amount_left = (amount * pow(C,y_h));

  printf("Year: %.0f           Amount: %.3f\n", year, amount_left);

  year += 1;

}

}