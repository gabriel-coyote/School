#include <stdio.h>
#include <stdlib.h>


//FUNCTION Prototype
int fib(int n);
int fib_helper(int nth, int previous, int result);

//MAIn FUNCTION
int main(void) {
	int fib_n;
	int N;

	printf("Enter the nth number you want from the Fibonacci sequence: ");
	scanf("%d", &N);

	fib_n = fib(N);
  printf("\n\n\nnth Fib # = %d\n", fib_n);
  return 0;
}



int fib(int n){
	return fib_helper(n, 0, 1);
}


int fib_helper(int nth, int previous, int total){
	printf("\nnth : %d   prev: %d  reuslt: %d", nth, previous, total);
	if(nth == 0){
		return 0;
	} 
	if(nth ==1){
		return total;
	}
	else{
		return fib_helper(nth-1,total ,total+previous);
	}
}