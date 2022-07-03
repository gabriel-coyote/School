// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab6_Problem 1.c
// SPECIFICATION:       Given inputted 12-digit code, compute a check digit to compare. Print out either, "validated" or "error in barcode".
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)


#include <stdio.h>

//Function Prototypes
int compute_check_digit(int user_barcode[]);
void check_match(int check_digit, int last_digit);
void input_array(int user_barcode[]);




///MAIN FUNCTION
int main(void) {

  int user_barcode[12]; //Array to store user 12-digits
  int computed_check_digit;  //Interger variable: Stores the computed check-digit


  input_array(user_barcode);

  computed_check_digit = compute_check_digit(user_barcode);

  check_match(computed_check_digit,user_barcode[11]);  //"user_barcode[11]" is the last digit, therefore the original check digit


  return 0;
}







// NAME:              input_array
// INPUT PARAMETERS:  A integer array: 'user_barcode[]'
// OUTPUT:            Prints to the console, and scans input. No Returns; Assigns integers to indexes of array.
// PURPOSE:           The functions scans in the 12-digit code, and assigns it to the proper indexes of the "user_barcode[]" array.

void input_array(int user_barcode[]){
  int a,b,c,d,e,f,g,h,i,j,k,l;  //Interger variables: Stores the 12 digits of the inputted barcode

  printf("Enter the barcode's 12 digits SEPARATED by spaces:");
  scanf(" %d %d %d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);

  //Assigning the 12 inputted digits to their respected index in the array, "user_code"
  user_barcode[0] = a;
  user_barcode[1] = b;
  user_barcode[2] = c;
  user_barcode[3] = d;
  user_barcode[4] = e;
  user_barcode[5] = f;
  user_barcode[6] = g;
  user_barcode[7] = h;
  user_barcode[8] = i;
  user_barcode[9] = j;
  user_barcode[10] = k;
  user_barcode[11] = l;
}







// NAME:              computer_check_digit
// INPUT PARAMETERS:  A integer array: "user_barcode[]"
// OUTPUT:            Returns the value of the computed check_digit. Prints out "the result from step #" & the resultant to the console. 
// PURPOSE:           The function computes the check digit from the first 11 digits of the code, and returns the value of it.

int compute_check_digit(int user_barcode[]){
  int check_digit;
  
  //Step 1 
  for(int i = 0; i < 11; i += 2){
    check_digit += user_barcode[i]; 
  }
  check_digit *= 3;
  printf("\nThe result from step 1: %d", check_digit);


  //Step 2
  for(int q = 1; q < 11; q += 2){
    check_digit += user_barcode[q];
  }
  printf("\nThe resul from step 2: %d", check_digit);

return check_digit;
}





// NAME:              check_match
// INPUT PARAMETERS:  An integer: "check_digit" & "last_digit"
// OUTPUT:            Prints out either "validated" || "error in barcode" to the console
// PURPOSE:           The function uses the last digit in the computed check_digit and somputes the single digit check_digit. Compares it to the orginial check_digit (The last digit in the 12 digit barcode). Determines whether its valid or not. 

void check_match(int check_digit, int last_digit){

  int single_digit_Check_Digit; //An integer variable: Stores computed single digit check digit

  if((check_digit %10) == 0){ //If last digit of computed check_digit is 0, the single_digit_Check_Digit is 0
    single_digit_Check_Digit = 0;

  }else{
    single_digit_Check_Digit = 10-(check_digit %10); //Else single_digit_Check_Digit is (10-(last digit of computed check digit))
  }

  if(single_digit_Check_Digit == last_digit){ //Checks if their equal
      printf("\n\nvalidated");

  } else{
      printf("\nerror in barcode");
  }

}