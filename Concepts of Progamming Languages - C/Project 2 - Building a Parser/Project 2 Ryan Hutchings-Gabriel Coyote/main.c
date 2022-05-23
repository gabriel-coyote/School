// CS 3361 - PROJECT 2 (Parser)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Keywords (State #) */
#define READ 21
#define WRITE 22
#define $$ 0

/* Tokens (State #) */
/* - Used in:  Token Array "token_tab" */
#define DIV 2
#define LPAREN 6
#define RPAREN 7
#define PLUS 8
#define MINUS 9
#define TIMES 10
#define ASSIGN 12
#define NUMBER_a 14
#define NUMBER_b 15
#define ID 16
#define W_SPACE 17
#define COMMENT 18

/* GLOBAL Token Array */
/* TOKEN's state#/value := index in array */
int token_tab[19] = { 0, 0, DIV, 0, 0, 0, LPAREN, RPAREN, PLUS, MINUS, TIMES, 0, ASSIGN, 0, NUMBER_a, NUMBER_b, ID, W_SPACE, COMMENT};


/*GLOBAL  Scanner Table */
/* [Cur_State][Cur_Char] := new_state */
/* Row [0][j] will not be used */
int scan_tab[19][14] = { {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {17, 17, 2, 10, 6, 7, 8, 9, 11, -1, 13, 14, 16, -1},
												 {-1, -1, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {3, 18, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
												 {4, 4, 4, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
												 {4, 4, 18, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, 14, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 15, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 16, 16, -1},
												 {17, 17, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
												 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};






//Int_cur_char_Function -----------------------------------------
int Int_cur_char(char ch){

	//Gets Column index value of Current Char to use in Scanner Table: "scan_tab[][index]"
	if(ch == ' '){
		return 0;
	}else if( ch == '\t'){
		return 0;
	}else if( ch == '\n' || ch == '\r'){			/* Windows has newline '\r\n' */
		return 1;
	}else if( ch == '/'){
		return 2;
	}else if( ch == '*'){
		return 3;
	}else if( ch == '('){
		return 4;
	}else if( ch == ')'){
		return 5;
	}else if( ch == '+'){
		return 6;
	}else if( ch == '-'){
		return 7;
	}else if( ch == ':'){
		return 8;
	}else if( ch == '='){
		return 9;
	}else if( ch == '.'){
		return 10;
	}else if( isdigit(ch) != 0){		/* is a digit */
		return 11;
	}else if( isalpha(ch) != 0){		/* is a letter */
		return 12;
	}else{													/* other */
		return 13;
	}

}


//SCAN_Function -------------------------------------------------
int scan(FILE *File_PTR, char cur_char, int cur_state, int remembered_state, char image[]){

	int token; 																						/* tok in psuedo code */



	/* while not EOF */
	while(  !feof(File_PTR) ){
		if( !feof(File_PTR) ){

			cur_char = fgetc(File_PTR);												/* read current char */

			/* MOVE Action */
			if( scan_tab[cur_state][Int_cur_char(cur_char)] != -1){
				/* Means at this Position in Scanner Table it has a number*/
				if( token_tab[cur_state] != 0){										/* This could be a final state */
					remembered_state = cur_state;
					// [ remembered chars := empty_string ]
				}

				// [ Add cur_char to remember_chars ]
				cur_state = scan_tab[cur_state][Int_cur_char(cur_char)];

				/* RECOFNIZE Action */
			} else if( scan_tab[cur_state][Int_cur_char(cur_char)] == -1 && token_tab[cur_state] != 0){
				token = token_tab[cur_state];
				ungetc(cur_char, File_PTR);												/* unread cur_char */
				return token;

			/* ERROR */
			}else{
				printf("\nerror.");
				exit(0);
			}


			/* Append cur_char to image */
			strncat(image, &cur_char, 1);
		}
	}
}





//DRIVER_Function -----------------------------------------------
void Driver(FILE *File_PTR, int tokens_store[], char tokens_value[200][20]){

	int i = 0;											/* index for tokens_store */
	int tok;												/* Holds one Token State # */
	char cur_char;


  // [ char remembered_chars[] = ""; 				//list of char ]
	char image[80];									/* holds tok string value */




	/* While File isnt EOF */
	while ( !feof(File_PTR) ){
		if( !feof(File_PTR) ){

			int cur_state = 1;									/* Equal to Start State (1) */
			int remembered_state = 0; 					/* none */
			memset(image, '\0', strlen(image));		/* Zero entire contents of image */

			tok = scan(File_PTR, cur_char, cur_state, remembered_state, image);


			if(strcmp(image, "read") == 0){		// Equal or Same
				tok = READ;
				tokens_store[i] = tok;					/* store tok into tokens_store array */
				strcpy(tokens_value[i], image); /* store tok value in array*/
				//printf("[Token value: %s ]\n", image);
				i++;

			}else if (strcmp(image, "write") == 0){
				tok = WRITE;
				tokens_store[i] = tok;					/* store tok into tokens_store array */
				strcpy(tokens_value[i], image); /* store tok value in array*/
				//printf("[Token value: %s ]\n", image);
				i++;

			}else if (tok == W_SPACE || tok == COMMENT){
				/* Don't store token */
			}else{
				/* leave tok as is & add to tokens_stored array to be printed */
				tokens_store[i] = tok;					/* store tok into tokens_store array */
				strcpy(tokens_value[i], image); /* store tok value in array*/
				//printf("[Token value: %s ]\n", image);
				i++;
			}



		}
	}
	//End Repeat
}







//printTokens_Function -------------------------------------------
void print_tokens(int tokens_stored[]){
	int i = 0;
	printf("(");

	while( tokens_stored[i] != 0){						/* 0 value means no more tokens */

	  if(tokens_stored[i] == DIV){
			printf("div");
		}else if(tokens_stored[i] == LPAREN){
			printf("iparen");
		}else if(tokens_stored[i] == RPAREN){
			printf("rparen");
		}else if(tokens_stored[i] == PLUS){
			printf("plus");
		}else if(tokens_stored[i] == MINUS){
			printf("minus");
		}else if(tokens_stored[i] == TIMES){
			printf("times");
		}else if(tokens_stored[i] == ASSIGN){
			printf("assign");
		}else if(tokens_stored[i] == NUMBER_a){
			printf("number");
		}else if(tokens_stored[i] == NUMBER_b){
			printf("number");
		}else if(tokens_stored[i] == ID){
			printf("id");
		}else if(tokens_stored[i] == READ){
			printf("read");
		}else if(tokens_stored[i] == WRITE){
			printf("write");
		}else{
			printf("\n\t[ERROR in Print Tokens Function!]");
		}

		i++;

		/* If there are more tokens to print */
		if(tokens_stored[i] != 0){
			printf(", ");

		/* If there are NO MORE tokens to print */
		}else if(tokens_stored[i] == 0){
			printf(").");
		}else{}
	}
}





//----------------------------------------------------------------
//----------------------------------------------------------------
//----------------------------------------------------------------
//FUNCTION PROTOTYPES for Parsing
void program(int tokens_stored[], int index, int tabs, char tokens_value[200][20], int *error, int print);

void stmt_list(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void stmt(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void expr(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void term_tail(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void term(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void factor_tail(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void factor(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void add_op(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
void mult_op(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print);
// parser helper FUNCTIONS ---------------------------------------

void match(int expected, int tokens_stored[], int *curr_index, int *error){

	//printf("INSIDE OF MATCH; %d == %d\n", tokens_stored[*curr_index], expected);
	if(expected == NUMBER_a || expected == NUMBER_b){
		if(tokens_stored[*curr_index] == NUMBER_a || tokens_stored[*curr_index] == NUMBER_b){
			*curr_index += 1;
		}
	}

	else if (tokens_stored[*curr_index] == expected){
		/* Consume the current tok ; move to next token */
		*curr_index += 1;
	}

	else{*error = 1;}
}



void program(int tokens_stored[], int index, int tabs, char tokens_value[200][20], int *error, int print){
	int idents = tabs;//Make local variable to holds tabs number

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<Program>\n");
	}
	idents = tabs; //reset indents for end print of function


	if( tokens_stored[index] == ID ||
			tokens_stored[index] == READ ||
			tokens_stored[index] == WRITE ||
			tokens_stored[index] == $$){

		stmt_list(tokens_stored, &index, tabs, tokens_value, error, print);
		match($$, tokens_stored, &index, error);

	}else{  *error = 1; }


	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</Program>\n");
	}
}




void stmt_list(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<stmt_list>\n");
	}
	idents = tabs; //reset indents for end print of function


	if( tokens_stored[*index] == ID ||
			tokens_stored[*index] == READ ||
			tokens_stored[*index] == WRITE ){

		stmt(tokens_stored, index, tabs, tokens_value, error, print);
		stmt_list(tokens_stored, index, tabs, tokens_value, error, print);
	}

	else if( tokens_stored[*index] == $$){/* skip   --epsilon production */}

	else{ *error = 1;}

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</stmt_list>\n");
	}
}




void stmt(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number

	if(print ==1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<stmt>\n");
	}
	idents = tabs; //reset indents for end print of function



	int index_cur = *index;
	int tabs2 = tabs + 1;//Make local variable to holds tabs number + 1
	if ( tokens_stored[*index] == ID){

		//ID  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<id>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(ID, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</id>\n");
		}

		//ASSIGN  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		tabs2 = tabs + 1; //reset tabs 2
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<assign>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(ASSIGN, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[++index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</assign>\n");
		}

		expr(tokens_stored, index, tabs, tokens_value, error, print);
	}




	else if(tokens_stored[*index] == READ){

		//READ  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<read>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(READ, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</read>\n");
		}

		//ID  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		tabs2 = tabs + 1; //reset tabs 2
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<id>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(ID, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[++index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</id>\n");
		}
	}

	else if(tokens_stored[*index] == WRITE){

		//WRITE  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<write>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(WRITE, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</write>\n");
		}


		expr(tokens_stored, index, tabs, tokens_value, error, print);
	}

	else{  *error = 1;}

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</stmt>\n");
	}
}



void expr(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<expr>\n");
	}
	idents = tabs; //reset indents for end print of function


	if (tokens_stored[*index] == ID ||
			tokens_stored[*index] == NUMBER_a ||
			tokens_stored[*index] == NUMBER_b ||
			tokens_stored[*index] == LPAREN){

		term(tokens_stored, index, tabs, tokens_value, error, print);
		term_tail(tokens_stored, index,tabs, tokens_value, error, print);
	}

	else{ *error = 1; }

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</expr>\n");
	}
}



void term_tail(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<term_tail>\n");
	}
	idents = tabs; //reset indents for end print of function


	if (tokens_stored[*index] == PLUS ||
			tokens_stored[*index] == MINUS){

		add_op(tokens_stored, index, tabs, tokens_value, error, print);
		term(tokens_stored, index, tabs, tokens_value, error, print);
		term_tail(tokens_stored, index, tabs, tokens_value, error, print);
	}

	else if (tokens_stored[*index] == RPAREN ||
					 tokens_stored[*index] == ID ||
					 tokens_stored[*index] == READ ||
					 tokens_stored[*index] == WRITE ||
					 tokens_stored[*index] == $$){

		/* skip   --epsilon production */
	}

	else{  *error = 1; }

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</term_tail>\n");
	}
}



void term(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<term>\n");
	}
	idents = tabs; //reset indents for end print of function


	if (tokens_stored[*index] == ID ||
			tokens_stored[*index] == NUMBER_a ||
			tokens_stored[*index] == NUMBER_b ||
			tokens_stored[*index] == LPAREN){

		factor(tokens_stored, index, tabs, tokens_value, error, print);
		factor_tail(tokens_stored, index, tabs, tokens_value, error, print);
	}

	else{  *error = 1; }

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</term>\n");
	}
}



void factor_tail(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<factor_tail>\n");
	}
	idents = tabs; //reset indents for end print of function


	if (tokens_stored[*index] == TIMES ||
			tokens_stored[*index] == DIV){

		mult_op(tokens_stored, index, tabs, tokens_value, error, print);
		factor(tokens_stored, index, tabs, tokens_value, error, print);
		factor_tail(tokens_stored, index, tabs, tokens_value, error, print);
	}

	else if (tokens_stored[*index] == PLUS ||
					 tokens_stored[*index] == MINUS ||
					 tokens_stored[*index] == RPAREN ||
					 tokens_stored[*index] == ID ||
					 tokens_stored[*index] == READ ||
					 tokens_stored[*index] == WRITE ||
					 tokens_stored[*index] == $$){

		/* skip   --epsilon production */
	}

	else{  *error = 1; }

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</factor_tail>\n");
	}
}


//NUmber FIX!!
void factor(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<factor>\n");
	}
	idents = tabs; //reset indents for end print of function

	int index_cur = *index;
	int tabs2 = tabs + 1;//Make local variable to holds tabs number + 1
	if (tokens_stored[*index] == ID){

		//ID  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<id>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(ID, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</id>\n");
		}
	}


	else if (tokens_stored[*index] == NUMBER_a ||
					 tokens_stored[*index] == NUMBER_b ){

		// NUMBER  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<number>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

			match(NUMBER_a, tokens_stored, index, error);			// MIGHT NEED TO FIX THIS
			match(NUMBER_b, tokens_stored, index, error);

			tabs2++;	//For printing the acutal token value
			if(print == 1){
			while(tabs2 > 0) {printf("\t"); tabs2--;}
			printf("%s\n", tokens_value[index_cur]);
			}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</number>\n");
		}

	}

	else if (tokens_stored[*index] == LPAREN){

		//LPAREN  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<lparen>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(LPAREN, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</lparen>\n");
		}


		expr(tokens_stored, index, tabs, tokens_value, error, print);

		// RPAREN  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		tabs2 = tabs + 1;	//reset tabs 2
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<rparen>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(RPAREN, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[++index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</rparen>\n");
		}
	}

	else{  *error = 1;}

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</factor>\n");
	}
}



void add_op(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<add_op>\n");
	}
	idents = tabs; //reset indents for end print of function


	int index_cur = *index;
	int tabs2 = tabs + 1;//Make local variable to holds tabs number + 1
	if (tokens_stored[*index] == PLUS){

		//PLUS !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<plus>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(PLUS, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</plus>\n");
		}
	}

	else if (tokens_stored[*index] == MINUS){

		//MINUS  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<minus>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(MINUS, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</minus>\n");
		}
	}

	else{ *error = 1;}

	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</add_op>\n");
	}
}




void mult_op(int tokens_stored[], int *index, int tabs, char tokens_value[200][20], int *error, int print){
	tabs++;
	int idents = tabs;//Make local variable to holds tabs number
	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("<mult_op>\n");
	}
	idents = tabs; //reset indents for end print of function


	int index_cur = *index;
	int tabs2 = tabs + 1;//Make local variable to holds tabs number + 1
	if (tokens_stored[*index] == TIMES){

		//TIMES !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<times>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(TIMES, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1; //reset tabs 2
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</times>\n");
		}
	}

	else if (tokens_stored[*index] == DIV){

		//DIV  !!!!!!!!!!!!!!!!!!!!!!!!!!!
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("<div>\n");
		}
		tabs2 = tabs + 1; //reset tabs 2

				match(DIV, tokens_stored, index, error);

				tabs2++;	//For printing the acutal token value
				if(print == 1){
				while(tabs2 > 0) {printf("\t"); tabs2--;}
				printf("%s\n", tokens_value[index_cur]);
				}

		tabs2 = tabs + 1;
		if(print == 1){
		while(tabs2 > 0) {printf("\t"); tabs2--;}
		printf("</div>\n");
		}
	}

	else{*error = 1;}


	if(print == 1){
	while(idents > 0) {printf("\t"); idents--;}
	printf("</mult_op>\n");
	}
}




//----------------------------------------------------------------
//----------------------------------------------------------------
//MAIN -----------------------------------------------------------
int main(int argc, char **argv) {

	//char scanner[10];
	char filename[25];

	//printf("Scanner/Parser  PROJECTS\n\n");
	//scanf(" %s %s", scanner, filename);
	//scanf(" %s", filename);
	//printf("Filename = %s\n____________________________\n\n", filename);



	//Open Filename
	FILE *inputFile;
	inputFile = fopen(argv[1], "r");
	//inputFile = fopen(filename, "r");




	/* Stored Token Array */
	/* Holds 200 tokens; all values set to 0 intially*/
	int tokens_stored[200];
	memset(tokens_stored, 0, 200);

	/* Stored Token Values (of  values length max 20) Array */
	/* Holds 200 tokens values; all values set to '\0' (null terminator) intially*/
	char tokens_values[200][20];
	memset(tokens_values, '\0', 200);



	if( inputFile ){
		Driver(inputFile, tokens_stored, tokens_values);
		//print_tokens(tokens_stored);




		/* parser */
		printf("\n\n");

		int error = 0;
		int print = 0;	//If print is 1, then print to console

		program(tokens_stored, 0, 0, tokens_values, &error, print);
		//Doesn't print; just checks for error

		if (error == 1){
			printf("\n\nError.\n\n");
		}else{
			print = 1;
			program(tokens_stored, 0, 0, tokens_values, &error, print);
			//Actually prints parser, if no errors
		}



		fclose(inputFile);
		//getchar();		//press enter to finsih program
	}else{ printf("\n[File can not be found!]\n\n");}


  return 0;
}
