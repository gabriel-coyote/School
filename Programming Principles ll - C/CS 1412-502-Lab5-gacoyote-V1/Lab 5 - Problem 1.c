// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab 5 - Problem 1.c
// SPECIFICATION:       Make a simple calculator program, each data line has the next operation followed by a value.
//                      Initial value is set to 0. After each calculation print the result. If given 'q' programs ends.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)




#include <stdio.h>
#include <math.h>


//Function Prototypes
void scan_data(char *oper, float *num);
void do_next_op(char operation, float num, float *accumulator);


//MAIN FUNCTION
int main(void) {

  float total = 0;  //Initial Value = 0
  char operation;   // Operation to perform.
  float number;     //The number to perfrom with.

  scan_data(&operation, &number);

  while(1){
    if(operation == 'q' || operation == 'Q'){
      break;  //If 'q' or 'Q' is entered exit loop.
    }
    do_next_op(operation,number,&total);
    scan_data(&operation, &number);
  }

  printf("final result is %.1f", total);

 return 0;
}




// NAME:              scan_data
// INPUT PARAMETERS:  No input parameters; Two Output Paramters: 'char *oper' and 'float *num'.
// OUTPUT:            No Return value; Has two output parameters; Char output parameter for operation symbol,
//                    float ouput parameter for the number to use.
// PURPOSE:           The function scans input from user, and assigns the operation
//                    and number to its respected variable in the main function.

void scan_data(char *oper, float *num){
  char operation;
  float number;
  scanf(" %c  %f", &operation, &number);

  *oper = operation;
  *num = number;
}






// NAME:              do_next_op
// INPUT PARAMETERS:  Two inputs; A character 'operation' and a float 'num',
//                    and input/ouput parameter float 'accumulator'.
// OUTPUT:            No Return value: One ouput parameter, a "float *accumulator"
//                    which returns the the current total after calculations.
//                    After each calculations the function prints the current total/accumulator.
// PURPOSE:          The function performs calucations based off the opertion symbol,
//                   and with the number selected; returns it as an output parameter "float *acccumulator"
//                   to the main function's "total" variable.

void do_next_op(char operation, float num, float *accumulator){

   switch(operation){
     case '+':
      *accumulator += num;
      break;

     case '-':
      *accumulator -= num;
      break;

     case '*':
      *accumulator *= num;
      break;

     case '/':
      *accumulator /= num;
      break;

     case '^':
      *accumulator = pow(*accumulator, num);
      break;

     default:
      break;
    }
  printf("result so far is %.1f\n", *accumulator);
}
