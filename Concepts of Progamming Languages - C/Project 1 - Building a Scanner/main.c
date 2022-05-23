#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Keywords (State #) */
#define READ 21
#define WRITE 22

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
				printf("\nerror.\n");
				exit(0);
			}


			/* Append cur_char to image */
			strncat(image, &cur_char, 1);
		}
	}
}





//DRIVER_Function -----------------------------------------------
void Driver(FILE *File_PTR, int tokens_store[]){

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
			}else if (strcmp(image, "write") == 0){
				tok = WRITE;
			}else{
				/* leave tok as is */
			}


			tokens_store[i] = tok;					/* store tok into tokens_store array */
			i++;
		}
	}
	//End Repeat
}







//printTokens_Function -------------------------------------------
void print_tokens(int tokens_stored[]){
	int i = 0;
	printf("\n(");

	while( tokens_stored[i] != 0){						/* 0 value means no more tokens */

		if(tokens_stored[i] == W_SPACE || tokens_stored[i] == COMMENT){
			/* Don't print SPACE or COMMENT tokens */
		}else if(tokens_stored[i] == DIV){
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
			if(tokens_stored[i] == W_SPACE || tokens_stored[i] == COMMENT){
				/* Don't print ',' if tokens are SPACE or COMMENT*/
			}else{
				printf(", ");
			}
		}else if(tokens_stored[i] == 0){
			printf(").\n");
		}else{}
	}
}






//MAIN -----------------------------------------------------------
int main(int argc, char **argv) {
  /*
	char scanner[10];
	char filename[25];

	//printf("Gabriel Coyote; 3361 Project 1 Scanner\n\n");
	scanf(" %s %s", scanner, filename);
	//printf("Filename = %s\n____________________________\n\n", filename);
	*/


	//Open Filename
	FILE *inputFile;
	inputFile = fopen(argv[1], "r");



	/* Stored Token Array */
	/* Holds 200 tokens; all values set to 0 intially*/
	int tokens_stored[200];
	memset(tokens_stored, 0, 200);

	if( inputFile ){
		Driver(inputFile, tokens_stored);
		print_tokens(tokens_stored);

		fclose(inputFile);
		//getchar();		//press enter to finsih program
	}else{ /* File can't be open or doesn't exist */ }


  return 0;
}
