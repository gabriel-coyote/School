#include <stdio.h>


//STRUCTURE
typedef struct{
	int numerator;
	int denominator;
} fraction;



//FUNCTION PROTOTYPE: Passing Structures as argurements
int cmp(fraction, fraction);



//MAIN FUNCTION
int main(void) {
  

	fraction A; //Structure fraction "A"
	fraction B; //Structure Fraction "B"

	char trash1, trash2, trash3; //Holds the '/' symbol and space ' ' 

	printf("\nINPUT MUST BE: 'A/B C/D'");
	printf("\n\nENTER INPUT: ");
	scanf(" %d%c%d%c%d%c%d",&A.numerator, &trash1,&A.denominator, &trash2, &B.numerator, &trash3, &B.denominator);


	switch(cmp(A,B)){
		case 0:
			printf("\nFaction (%d/%d) & (%d/%d) are equal", A.numerator, A.denominator, B.numerator,B.denominator);
			break;

		case 1:
			printf("\nFaction (%d/%d) > (%d/%d)", A.numerator, A.denominator, B.numerator,B.denominator);
			break;

		case -1:
			printf("\nFaction (%d/%d) < (%d/%d)", A.numerator, A.denominator, B.numerator,B.denominator);
			break;

		default:
			printf("\nInvalid Input");
			break;
	}
  return 0;
}





//FUNCTION;
//RERTURNS: 0 for equal, 1 if A>B, -1 if A<B
int cmp(fraction A, fraction B){
	
	float FRACTION_1 = (float)A.numerator / (float)A.denominator;

	float FRACTION_2 = (float)B.numerator / (float)B.denominator;

	if(FRACTION_1 ==  FRACTION_2){
		return 0;
	}else if(FRACTION_1 > FRACTION_2){
		return 1;
	}else if(FRACTION_1 < FRACTION_2){
		return -1;
	}else{
		return 999;
	}

}