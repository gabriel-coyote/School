// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab7_Problem 1.c
// SPECIFICATION:       Write a program that stores list of names, and ages. Prints the orginal list, and alphabetized listed along with who was the youngest, and the avgerage age of the list.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//CONSTANT MACROS
#define MAX_STR_SIZE 30 //String length max: 30
#define USERMAX 20      //List holds a max of 20 people



// Function Prototypes
void make_fill_list(void);
int alpha_first(char *sorted_names[], int min_sub, int max_sub);
void sort_str(char *sorted_names[], int * ages_list[], int num_of_People);
void display_youngest_avg(char *sorted_names[], int *ages_list[], int num_People);





//MAIN FUNCTION
int main()
{
  //call 'make_fill_list' function
  make_fill_list();

    return 0;
} 







// NAME:              make_fill_list
// INPUT PARAMETERS:  none: void
// OUTPUT:            NO RETURNS; prints to console a series of statements asking for input; prints to console original list and alphabetized list along with youngest person & avg age
// PURPOSE:           The functions gets the array size from user input, then scans in name(string) & ages(integer) to fill into their respeted arrays; Calls a sorting function to sort the arrays alphabetically; also calls a function to determin youngest person & avg age

void make_fill_list(void){

  char Names[USERMAX][MAX_STR_SIZE];
    int ages[USERMAX];  
  
    char* sorted_names[USERMAX];
    int* ages_list[USERMAX];  //sorted 

    int num_People;
    int i;
    int k;
    char one_char;


    // prompt the user to enter how many people to store
    printf("Enter number of people (Max [%d]): ", USERMAX);
    scanf("%d", &num_People);
  

    // repeat the loop for each individual person
    for (i = 0; i < num_People; i++) {
        // prompt the user to enter name
        scanf("%c", &one_char);
        printf("\nEnter name (lastname, firstname): ");      
        k = 0;
        while ((one_char = (char)getchar()) != '\n' && k < MAX_STR_SIZE){
            Names[i][k++] = one_char;
        }
        Names[i][k] = '\0';

        // prompt the user to enter the age
        printf("Enter age: ");
        scanf("%d", &ages[i]);

        //Dynamically allocates memory in order to copy strings successfully
        sorted_names[i] = (char*)malloc(strlen(Names[i]) * sizeof(char));
        strcpy(sorted_names[i], Names[i]);
        ages_list[i] = &ages[i];
    }


    // print the original list
    printf("\n\nOriginal list");
    printf("\n----------------------------\n");
    for (i = 0; i < num_People; ++i){
        printf("  %-25s%2d\n", Names[i], ages[i]);
    }


    // call the sort_str function
    sort_str(sorted_names, ages_list, num_People);
  

    // print the alphabetized list
    printf("\n\nAlphabetized list");
    printf("\n----------------------------\n");
    for (i = 0; i < num_People; ++i){
        printf("  %-25s%2d\n", sorted_names[i], *ages_list[i]);
    }


    //calling function to print youngest person, and age average
    display_youngest_avg(sorted_names, ages_list, num_People);

}








// NAME:              alpha_first
// INPUT PARAMETERS:  A chararacter array: '*sorted_names[]', and two integers
// OUTPUT:            Returns an integer (first) that declares the index of the min value of the string
// PURPOSE:           The functions determines min index value of string to return to "sort_str" function to help sorts the list of names in alphabetical order. 
int alpha_first(char* sorted_names[], int min_sub, int max_sub)
{
    int first, i;

    first = min_sub;
    for (i = min_sub + 1; i <= max_sub; ++i)
        if (strcmp(sorted_names[i], sorted_names[first]) < 0)
            first = i;

    return (first);
} // end of alpha_first function









// NAME:              sort_str
// INPUT PARAMETERS:  A chararacter array: '*sorted_names[]',  A integer array: '*ages_list[], and a integer 'num_of_People'
// OUTPUT:            NO RETURN: alphabetized the orginal list of names and their respected age value in the 'ages_list' array
// PURPOSE:           The functions, with help of another function(alpha_first), sorts the original list of names into a sorted names array alphabetically, along with sorting the ages with their respected person into a sorted ages array

void sort_str(char *sorted_names[], int * ages_list[], int num_of_People)
{
    int fill, index_of_min;
    char* temp;
    int* tempNum;

    for (fill = 0; fill < num_of_People - 1; ++fill)
    {
        // call the alpha_first function
        index_of_min = alpha_first(sorted_names, fill, num_of_People - 1);

        if (index_of_min != fill)
        {
            // swap the names
            temp = (char*)malloc(strlen(sorted_names[fill]) * sizeof(char));
            strcpy(temp, sorted_names[index_of_min]);
            strcpy(sorted_names[index_of_min], sorted_names[fill]);
            strcpy(sorted_names[fill], temp);

            // swap the ages
            tempNum = ages_list[index_of_min];
           ages_list[index_of_min] =ages_list[fill];
            ages_list[fill] = tempNum;
        }
    }
} 







// NAME:              display_youngest_avg
// INPUT PARAMETERS:  A chararacter array: '*sorted_names[]',  A integer array: '*ages_list[], and a integer 'num_of_People
// OUTPUT:            NO RETURNS: Prints to the console, the youngest person and their age; also prints the average age of the list
// PURPOSE:           The functions computes the list average age, and determines the youngest person in the list, and prints it out to the console

void display_youngest_avg(char *sorted_names[], int *ages_list[], int number_of_people){


int youngest = *ages_list[0];
int index_youngest;

for(int k =1; k < number_of_people; k++){
  if(*ages_list[k] < youngest){
    youngest = *ages_list[k];
    index_youngest = k;
  } 
}
printf("\nYoungest: %s %d", sorted_names[index_youngest],*ages_list[index_youngest]);


//Variables to Calculate avgerage age
  double *number;
  number = (double*)malloc(6 * sizeof(double));
  double sum = 0;
  double avg;

  //Calculates sum of ages
  for(int i = 0; i < number_of_people; i++){
    *number = *ages_list[i];
    sum += *number;
  }
  //Finds avgerage
  avg = (sum/number_of_people);
  printf("\nAge Average: %6.2lf", avg);


}