// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab13_Problem 1.c
// SPECIFICATION:       Write a program that converts an ordinary infix arithmetic expression (assume a valid expression is entered) with single digit integers to a postfix expression.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



//STACK WILL BE MAINTAINED 
//WITH THE FOLLOWING DECLARATIONS
struct stackNode {
  char data;
  struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;



//FUNCTION PROTOTYPES
void convertToPostfix( char infix[], char postfix[] );
int isOperator( char c );
int precedence( char operator1, char operator2 );
void push( StackNodePtr *topPtr, char value );
char pop( StackNodePtr *topPtr );
char stackTop( StackNodePtr topPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr topPtr ); 
void append(char *s, char c);



//MAIN FUNCTION
int main(void) {

  StackNodePtr stackPtr = NULL; //This points to stack top
  char *infix;
  char *postfix;
  char c; //to read in characther from user input

  infix = (char *)malloc(sizeof(char));
  postfix = (char *)malloc(sizeof(char));


  printf("\nEnter Arithmetic Expression with single digits integers,\n[!!!AND NO SPACES!!!] ");
  printf("\nExample: (6+2)*5-8/4");
  printf("\n\nENTER EXPRESSION: ");
  int i = 0;
  //Reads character to infix array until null from input
  while((c =  getchar()) != '\n'){
    realloc(infix, (sizeof(char))); //Decalres a warning; I ignored it for now
    infix[i++] = c;
  }
  infix[i] = '\0';//putting null back in
  
  printf("\n\nEntered Expression: %s\n", infix);

  

  //Push a left parenthesis '(' onto the stack
  push(&stackPtr, '(');

  //Append a right paranthesis ')' to the end of infix
  append(infix, ')');

  //While stack is not empty; read infix from left to right
  //isEmpty RETURNS 1 (if empty)
  int k =0;//use to Transverse through infix
  while(isEmpty(stackPtr) != 1){


    if(isdigit(infix[k]) != 0){ //isdigit(int) returns 0 if not a digit
      strcpy(&infix[k], &postfix[k]); //copy it to postfix if it is a digit
    } 
    

    if (strcmp(&infix[k], "(") == 0){//If current char is a left paranthesis; strcmp returns 0 if identical
      push(&stackPtr, infix[k]);//Push it onto stack
    }


    if (isOperator(infix[k])){
      //Pop operators (if there are any) at the top of the stack while they have equal or higher precedence than the current operator 
      
      while(isOperator(stackTop(stackPtr)) !=0){ //While the top of the stack is an operator
        if(precedence(infix[k], stackTop(stackPtr)) == 0 || precedence(infix[k], stackTop(stackPtr)) == -1){
          char pop_char;
          pop_char = pop(&stackPtr);
          strcpy(&postfix[k], &pop_char);// insert them in postfix 
        }
      }
      //Push the current character in infix onto the stack. 
      push(&stackPtr, infix[k]);
    }


    if (strcmp(&infix[k], ")") == 0){//If current char is a right paranthesis;
      char until;
      until = stackTop(stackPtr);

      while(strcmp(&until, "(") != 0){//do the following 'while code'  until a left paranthesis is at the top of the stack
        if(isOperator(stackTop(stackPtr)) == 1){//If top of stack is operator
          char popped_char;
          popped_char = pop(&stackPtr);
          strcpy(&postfix[k], &popped_char);// insert them in postfix 
        }
        until = stackTop(stackPtr);//for next go around in the while loop
      }
      //Pop (and discard) the left parenthesis from the stack. 
      char discard;
      discard = pop(&stackPtr);
      free(&discard);
    }

  }
  
  printf("Postfix : %s", postfix);
  
  return 0;
}










// NAME:              append(char *s, char c)
// INPUT PARAMETERS:  A chrachter pointer/array; and a character
// OUTPUT:            NO RETURNS;
// PURPOSE:           The functions purpose is to append a character onto a character array
void append(char *s, char c){
  int length = strlen(s);
  s[length] = c;
  s[length+1] = '\0';
}










// NAME:              convertToPostfix
// INPUT PARAMETERS:  TWO character Array; infix & postfix
// OUTPUT:            NO RETURNS;
// PURPOSE:           The functions purpose is to convert the infix expression to postfix notation
void convertToPostfix( char infix[], char postfix[] ){
  
}










// NAME:              isOperator
// INPUT PARAMETERS:  A character Pointer: c
// OUTPUT:            Returns 1 IF c is a Operator; Else return 0
// PURPOSE:           The functions purpose determine if c is an operator; I didn't include paranthesis() becuase the arithmetic operator was given.
int isOperator( char c ){
  //Operations:  + - * / ^ %
  char op1[] = "+";
  char op2[] = "-";
  char op3[] = "*";
  char op4[] = "/";
  char op5[] = "^";
  char op6[] = "%";

  //Test to determine ic c is an operator
  if (*op1 == c){
    return 1; //If char c is an Operator
  }else if (*op2 == c){
    return 1; //If char c is an Operator
  }else if (*op3 == c){
    return 1; //If char c is an Operator
  }else if (*op4 == c){
    return 1; //If char c is an Operator
  }else if (*op5 == c){
    return 1; //If char c is an Operator
  }else if (*op6 == c){
    return 1; //If char c is an Operator
  } else{
    return 0; //IF Char c IS NOT A Operator
  }
}









// NAME:              precedence
// INPUT PARAMETERS:  Two character pointers: c
// OUTPUT:            Returns -1 : If operator1 is less than operator2 precedence
//                    Returns 0 :  If operator1 is equal to operator2 precedence
//                    Returns 1 :  if operator1 is greater than operator2 precedence
// PURPOSE:           The functions purpose is to determine if the precedence of operator1 
//                     is less than, equal to, or greater than the precedence of operator2; 
//                    PRECEDENCE LEVLE: [^] > [* / %] > [+ -]
int precedence( char operator1, char operator2 ){
  //Operations:  + - * / ^ %
  char op1[] = "+";
  char op2[] = "-";
  char op3[] = "*";
  char op4[] = "/";
  char op5[] = "^";
  char op6[] = "%";
  int ERROR = 999;

  //Testing precedence
  if (operator1 == *op1){ //If Operator1 is a "+"
    if(operator2 == *op1 || operator2 == *op2){
      return 0; //equal precedence
    } else if (operator2 == *op3 || operator2 == *op4 || operator2 == *op5 || operator2 == *op6){
      return -1; //less than precedence
    }

  } else if (operator1 == *op2){ //If Operator1 is a "-"
    if(operator2 == *op2 || operator2 == *op1){
      return 0; //equal precedence
    } else if (operator2 == *op3 || operator2 == *op4 || operator2 == *op5 || operator2 == *op6){
      return -1; //less than precedence
    }
  }else if (operator1 == *op3){//If Operator1 is a "*"
    if(operator2 == *op3 || operator2 == *op4 || operator2 == *op6){ 
      return 0;//equal precedence
    } else if (operator2 == *op5){
      return -1;//Less than precedence
    } else if (operator2 == *op1 || operator2 == *op2){
      return 1;//Greater than precedence
    }

  }else if (operator1 == *op4){//If Operator1 is a "/"
    if(operator2 == *op4 || operator2 == *op3 || operator2 == *op6){ 
      return 0;//equal precedence
    } else if (operator2 == *op5){
      return -1;//Less than precedence
    } else if (operator2 == *op1 || operator2 == *op2){
      return 1;//Greater than precedence
    }

  }else if (operator1 == *op5){//If Operator1 is a "^"
    if (operator2 == *op5){
      return 0;//equal precedence
    } else if (operator2 == *op1 || operator2 == *op2 || operator2 == *op3 || operator2 == *op4 || operator2 == *op6){
      return -1;//less than precedence
    }
    
  }else if (operator1 == *op6){//If Operator1 is a "%"
    if(operator2 == *op6 || operator2 == *op3 || operator2 == *op4){ 
      return 0;//equal precedence
    } else if (operator2 == *op5){
      return -1;//Less than precedence
    } else if (operator2 == *op1 || operator2 == *op2){
      return 1;//Greater than precedence
    }
  } 
  
  return ERROR;
}










// NAME:              push
// INPUT PARAMETERS:  A StackNodePtr Pointer: topPtr and a character pointer: value
// OUTPUT:            NO RETURNS: 
// PURPOSE:           The functions purpose is to Push a value on the stack. 
void push( StackNodePtr *topPtr, char value ){
  StackNodePtr newPtr; //THis is a pointer to a new stackNode

  newPtr = malloc(sizeof(StackNode)); //Allocates memory to the "newPtr"

  //Insereting the node at the stack's top
  if (newPtr != NULL){
    newPtr->data = value;
    newPtr->nextPtr = *topPtr;
    *topPtr = newPtr;
  }
}











// NAME:              pop
// INPUT PARAMETERS:  A StackNodePtr Pointer: topPtr
// OUTPUT:            RETURNS A CHARACTER (pointer)
// PURPOSE:           The functions purpose is to Pop a value off the stack to return. 
char pop( StackNodePtr *topPtr ){
  StackNodePtr tempPtr; //A temporary node pointer
  int Pop_Value;

  tempPtr = *topPtr;
  Pop_Value = (*topPtr)->data; //Storing data
  *topPtr = (*topPtr)->nextPtr;
  free(tempPtr);//Frees the memory

  return Pop_Value;
}











// NAME:              stackTop
// INPUT PARAMETERS:  A StackNodePtr: topPtr
// OUTPUT:            RETURNS A CHARACTER (pointer)
// PURPOSE:           The functions purpose is to Return the top value of the stack without popping the stack. 
char stackTop( StackNodePtr topPtr ){
  int Stack_Top;
  Stack_Top = topPtr->data;
  return Stack_Top;
}













// NAME:              isEmpty
// INPUT PARAMETERS:  A StackNodePtr: topPtr
// OUTPUT:            RETURNS A INTEGER; 1 if empty else 0
// PURPOSE:           The functions purpose is to Determine if the stack is empty. 
int isEmpty( StackNodePtr topPtr ){
  return topPtr == NULL;
}












// NAME:              printStack
// INPUT PARAMETERS:  A StackNodePtr: topPtr
// OUTPUT:            RETURNS NOTHING; Prints Stak to console
// PURPOSE:           The functions purpose is to Print the stack. 
void printStack( StackNodePtr topPtr ){
  if (topPtr == NULL){
    printf("\nThe stack is empty bro :(...\n");
  }else{
    printf("The Stack Is: \n");

    while(topPtr != NULL){ //While the stack isn't empty
      printf("%c ", topPtr->data);
      topPtr = topPtr->nextPtr; //Transverse the stacks; goes to next node
    }
    
    printf("NULL\n");//once the stack is finished printing; print NULL
  }
} 