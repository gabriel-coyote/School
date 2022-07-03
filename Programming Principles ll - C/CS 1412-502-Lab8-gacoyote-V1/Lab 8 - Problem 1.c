// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab8_Problem 1.c
// SPECIFICATION:       Given number of elements to store, create an array and make it possible to search for a particular number within the array. (Printing it's index)
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)


#include <stdio.h>

//FUNCTION PROTOTYPE
void rearrange_asc(int arr[], int num_elements);
void search_arr(int arr[], int num_to_search, int middle_index);


//MAIN FUNCTION
int main(void) {

  int num_elements; //Array Size
  int num_to_search; //Number to serch for

  printf("Input the number of elements to store in the array: ");
  scanf(" %d", &num_elements);

  int arr[num_elements]; //Declare array size
  int middle_index = (num_elements/2);  //Used for search function recursion


 rearrange_asc(arr, num_elements); //Arranges the array in ascending order


 //Prints to cconsole the new Ascending ordered array for user to see
 printf("\nAscending Order Array:\n");
 printf("[");
 for(int i = 0; i < num_elements-1; i++){
  printf("%d, ", arr[i]);
} printf(" %d]\n", arr[num_elements-1]);


 printf("\nInput number to search : ");
 scanf(" %d", &num_to_search);


 search_arr(arr, num_to_search, middle_index);  //Prints out the index of the number in the array

  return 0;
}





// NAME:              rearrange_asc
// INPUT PARAMETERS:  A integer array: 'arr[]', and a interger: "num_elements"
// OUTPUT:            NO RETURNS; Prints to console asking user to input number of for each index in the array
// PURPOSE:           The functions scans in integers and assigns it into the array, then it sorts the array ascending order, (index 0 being the least and the last index being the biggest)
void rearrange_asc(int arr[], int num_elements){

  printf("\nInput %d elements to the array: ", num_elements);

  //Assigns inputted number into array, starting at index 0
  for(int i =0; i < num_elements; i++){
    printf("\nelement - %d: ", i);
    scanf(" %d", &arr[i]);
  }

  //Rearrange the array in ascending order 
  int temp; //Holds bigger value
   for(int i = 0; i < num_elements; i++){
      //Also taking in account if two values are equal
      for( int j = i+1; j<num_elements; j++){

        if(arr[i] > arr[j]){
         temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
        }

      }
    }

}





// NAME:              search_arr
// INPUT PARAMETERS:  A integer array: 'arr[]', A integer: "num_to_search", and a integer: "middle_index"
// OUTPUT:            NO RETURN; Prints to console where the search number is located in the array(it's index)
// PURPOSE:           The functions uses binaray search using recursion to find the index of the search number, and prints out where it is found.
void search_arr(int arr[], int num_to_search, int middle_index){

  //BASE CASE
  if(arr[middle_index] == num_to_search){
      printf("\nFound number %d in index %d", num_to_search, middle_index);
  } else if(arr[middle_index] > num_to_search){
      middle_index = (middle_index / 2);
      search_arr(arr, num_to_search, middle_index);
  } else if(arr[middle_index] < num_to_search){
      middle_index += middle_index/2;
      search_arr(arr, num_to_search, middle_index);
  } 
    
}