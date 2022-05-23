//Gabriel Coyote
//CS 2413 - Tuesday Lab
#include <stdio.h>
#include <string.h>

//FUNCTION PROTOTYPE
int num_of_strings(char *User_input, int length);





//MAIN FUNCTION
int main(void) {

	//Char array to hold user's string
	char User_str[50];
	int arr_size;

  printf("\nEnter String: ");
	scanf("%[^\n]", User_str);

	//User Inputted string length; L
	int Len = strlen(User_str);
	char separate[] = " ";//Use in strtok to separate at a space

	//Number of elements in array of strings
	arr_size = num_of_strings(User_str, Len);

	//Array to hold strings; number of strings and element size length(char) of max length of the inputted string meaning no spaces were entered
	char *str_arr[arr_size];

	//Creating elements(strings) to put in Array
	char *ptr = strtok(User_str, separate);
	int index = 0;
	while (ptr != NULL){
		//printf("%s\n", ptr);
		str_arr[index] = ptr;
		index++;
		ptr = strtok(NULL, separate);
	}

	//Print array elements
	for(int k = 0; k < arr_size+1; k++){
		printf("\nstr_arr[%d] = %s",k, str_arr[k]);
	}


	printf("\n\nArray of Strings:\n{");
	int i = 0;
	while (i < arr_size){
		printf("%s,", str_arr[i]);
		i++;
	}
	printf("%s}", str_arr[i]);




  return 0;
}






//FUNCTION:
//RETRURNS: NUMBER OF STRINGS BASED OFF SPACES
int num_of_strings(char *User_input, int length){

	//A counter; to return how many strings there are based off spaces
	int Num_of_str = 0;

	//pointer To transverse char array
	char *ptr = &User_input[0];

	while(*ptr != '\0'){
		if(strncmp(ptr, " ", 1) == 0){
			Num_of_str++;
		}
		ptr++;
	}

	//printf("\n number of strings: %d", Num_of_str);
	return Num_of_str;
}
