// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab11_Problem 1.c
// SPECIFICATION:       Develop a small airline reservation system. The database of flight information
//                      should be kept in a file of structures, have the option to create, delete, reserve, update, and cancel.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//STRUCTURES for Flight data
typedef struct {
  char flight_number[25];
  char city_departure[50];
  char destination[50];
  char date_time_depature[25];
  char date_time_arrival[25];
  int FirstClass_seats_open;
  int FirstClass_seats_sold;
  int coach_seats_open;
  int coach_seats_sold;
} Flights_t;


//FUNCTION PROTOTYPE
void create_record(Flights_t Flights[], int index);
void delete_FlightRecord(Flights_t Flights[], int index);
void update_FlightRecord(Flights_t Flights[], int index);
void make_reservation(Flights_t Flights[], int index);
void cancel_reservation(Flights_t Flights[], int index);





//MAIN FUNCTION
int main(void) {

  Flights_t Flights[100]; //Declares a maximum of 100 flights to be stored.

  FILE *outfile;

  int menu_num_pick; //Stores menu item picked
  int flight_index = 1; //Starting flight index for creation;
  //flight_index = 0 ; is reserve to clear a flight record

  //MENU OPTION FOR USER
  do {
    printf("\n1.) Create Flight Record");
    printf("\n2.) Delete Flight Reccord");
    printf("\n3.) Update Flight Record");
    printf("\n4.) Make A Reservation");
    printf("\n5.) Cancel A Reservation");
    printf("\n6.) EXIT; Creates 'FlightsData.txt'");
    printf("\n------Enter Option Number: ");
    scanf(" %d", &menu_num_pick);


    switch(menu_num_pick){
      case 1:
        create_record(Flights, flight_index);
        flight_index ++;
        break;

      case 2:
        delete_FlightRecord(Flights, flight_index);
        break;

      case 3:
        update_FlightRecord(Flights, flight_index);
        break;

      case 4:
        make_reservation(Flights, flight_index);
        break;

      case 5:
        cancel_reservation(Flights, flight_index);
        break;

      default:
        printf("\n-----EXITED-----\n");

    }
  } while (menu_num_pick != 6);


  //When menu is exited;    Create a "FlightsData.txt"
  outfile = fopen("FlightsData.txt", "w");

  for(int j = 0; j <= flight_index; j++){
    fprintf(outfile, "%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\t%d\n", Flights[j].flight_number, Flights[j].city_departure, Flights[j].destination, Flights[j].date_time_depature, Flights[j].date_time_arrival, Flights[j].FirstClass_seats_open, Flights[j].FirstClass_seats_sold, Flights[j].coach_seats_open, Flights[j].coach_seats_sold);
  }




  return 0;
}







// NAME:              create_record
// INPUT PARAMETERS:  A structure variable pointer array; 'Flights', and A integer "index"
// OUTPUT:            NO RETURN VALUE (VOID): Prompts users for information, scans information into their respected variables within thier Flights
// PURPOSE:           The functions purpose is to read information from user to store into the the Flights structure. Indexed with a array.
void create_record(Flights_t Flights[],int index){

  printf("\n\nEnter Flight Number: ");
  scanf(" %s", Flights[index].flight_number);
  printf("Enter City of Depature: ");
  scanf(" %s", Flights[index].city_departure);
  printf("Enter Destination: ");
  scanf(" %s", Flights[index].destination);
  printf("Enter Date and time of Depature in correct format (MMDD;hh:mm): ");
  scanf(" %s", Flights[index].date_time_depature);
  printf("Enter Date and time of arrival in correct format (MMDD;hh:mm): ");
  scanf(" %s", Flights[index].date_time_arrival);
  printf("Enter Number of first-class seats available: ");
  scanf(" %d", &Flights[index].FirstClass_seats_open);
  printf("Enter Number of first-class seats sold: ");
  scanf(" %d", &Flights[index].FirstClass_seats_sold);
  printf("Enter Number of coach seats available: ");
  scanf(" %d", &Flights[index].coach_seats_open);
  printf("Enter Number of coach seats sold: ");
  scanf(" %d", &Flights[index].coach_seats_sold);

}





// NAME:              delete_FlightRecord
// INPUT PARAMETERS:  A structure variable pointer array; 'Flights', and A integer "index"
// OUTPUT:            NO RETURN VALUE (VOID): Prompts users for which flight record to clear; Prints whether it's cleared or file could not be found
// PURPOSE:           The functions purpose is to search for a flight record and clear out that flight record data.
void delete_FlightRecord(Flights_t Flights[],int index){

  char search_flight_num[25];

  printf("\nEnter the Flight Number to Delete: ");
  scanf(" %s", search_flight_num);
  int i;

  //"FOR" search; looks for flights with the same name
  for(i =0; i < index; i++){
    if(strcmp(Flights[i].flight_number,search_flight_num) == 0){
      Flights[i] = Flights[0];
      printf("\n---The record has been cleared.---\n");
      break;
    }
  }
  if (i==index){
    printf("\n---The record could not be found!---\n");
  }
}





// NAME:              update_FlightRecord
// INPUT PARAMETERS:  A structure variable pointer array; 'Flights', and A integer "index"
// OUTPUT:            NO RETURN VALUE (VOID): Prompts users for which flight record to update; If found prompts user to enter updated details of the flight
// PURPOSE:           The functions purpose is to to search for a flight record, and updates its details base on user input, and print "file not found" if the flight record could not be found
void update_FlightRecord(Flights_t Flights[], int index){
  char search_for[25];
  int i;

  printf("\Enter the flight number to be updated: ");
  scanf(" %s", search_for);

  //"FOR" search; looks for flights with the same name
  for (i = 0; i < index; i++){
    if (strcmp(Flights[i].flight_number,search_for) == 0){//If flight record is found
      printf("Enter Updated City of Depature: ");
      scanf(" %s",Flights[i].city_departure);
      printf("Enter Updated Destination: ");
      scanf(" %s", Flights[i].destination);
      printf("Enter Updated Date and time of Depature in correct format (MMDD;hh:mm): ");
      scanf(" %s", Flights[i].date_time_depature);
      printf("Enter Updated Date and time of arrival: ");
      scanf(" %s", Flights[i].date_time_arrival);
      printf("Enter Updated Number of first-class seats available: ");
      scanf(" %d", &Flights[i].FirstClass_seats_open);
      printf("Enter Updated Number of first-class seats sold: ");
      scanf(" %d", &Flights[i].FirstClass_seats_sold);
      printf("Enter Updated Number of coach seats available: ");
      scanf(" %d", &Flights[i].coach_seats_open);
      printf("Enter Updated Number of coach seats sold: ");
      scanf(" %d", &Flights[i].coach_seats_sold);
      break;
    }
  }
  if(i == index){
    printf("\n---The record could not be found!---\n");
  }
}







// NAME:              make_reservation
// INPUT PARAMETERS:  A structure variable pointer array; 'Flights', and A integer "index"
// OUTPUT:            NO RETURN VALUE (VOID): Prompts users for which flight to resevere a seat in; if flight is found then prompt user for more input
// PURPOSE:           The functions purpose is to search for a flight record, and to reserve a seat (first-class or coach) within that flight details. If flight record can't be found print "record could not be found"
void make_reservation(Flights_t Flights[], int index){
  char flight_num[25];
  int i;
  int choice;

  printf("\nEnter the flight number to make reservations: ");
  scanf(" %s", flight_num);

  //"FOR" search; looks for flights with the same name
  for(i = 0; i < index; i++) {
     if(strcmp(Flights[i].flight_number, flight_num) == 0){
     printf("\nWhich seat do you want to resevere: ");
     printf("\n1.) First Class");
     printf("\n2.) Coach");

     printf("\nEnter number (1 or 2): ");
     scanf(" %d", &choice);

     if(choice == 1){ //First class seat
       if(Flights[i].FirstClass_seats_open <= 0){
         printf("\n---No first class seats are available!---\n");
         break;
       } else {
         Flights[i].FirstClass_seats_open = Flights[i].FirstClass_seats_open -1;
         Flights[i].FirstClass_seats_sold = Flights[i].FirstClass_seats_sold +1;
         printf("\n---First class seat is reserved.---\n");
         break;
       }

     } else if(choice == 2){ //Coaches seat
          if(Flights[i].coach_seats_open <= 0){
            printf("\n---No coach class seats are available!---\n");
            break;
          } else {
            Flights[i].coach_seats_open = Flights[i].coach_seats_open -1;
            Flights[i].coach_seats_sold = Flights[i].coach_seats_sold +1;
            printf("\n---Coach class seat is reserved.---\n");
            break;
       }
      }
     }

    } if (i==index){
    printf("\n---The record could not be found!---\n");
  }
}





// NAME:              cancel_reservation
// INPUT PARAMETERS:  A structure variable pointer array; 'Flights', and A integer "index"
// OUTPUT:            NO RETURN VALUE (VOID): Prompts users for which flight to cancel their seats in, if found prompt user for more input
// PURPOSE:           The functions purpose is to search for the flight record, and cancel the seat enter (first-class or Coach), if flight record is not found prompt "Record could not be found"
void cancel_reservation(Flights_t Flights[], int index){
  char flight_num[25];
  int i;
  int choice;

  printf("\nEnter the flight number to make cancel: ");
  scanf(" %s", flight_num);

  //"FOR" search; looks for flights with the same name
  for(i = 0; i < index; i++) {
     if(strcmp(Flights[i].flight_number, flight_num) == 0){
     printf("\nWhich seat do you want to cancel: ");
     printf("\n1.) First Class");
     printf("\n2.) Coach");

     printf("\nEnter number (1 or 2): ");
     scanf(" %d", &choice);

     if(choice == 1){ //First class seat
       if(Flights[i].FirstClass_seats_open <= 0){
         printf("\n---No first class seats are reserved!---\n");
         break;
       } else {
         Flights[i].FirstClass_seats_open = Flights[i].FirstClass_seats_open +1;
         Flights[i].FirstClass_seats_sold = Flights[i].FirstClass_seats_sold -1;
         printf("\n---First class seat is canceled.---\n");
         break;
       }

     } else if(choice == 2){ //Coaches seat
          if(Flights[i].FirstClass_seats_open <= 0){
            printf("\n---No coach class seats are reserved!---\n");
            break;
          } else {
            Flights[i].coach_seats_open = Flights[i].coach_seats_open +1;
            Flights[i].coach_seats_sold = Flights[i].coach_seats_sold -1;
            printf("\n---Coach class seat is canceled.---\n");
            break;
       }
      }
     }

    } if (i==index){
    printf("\n---The record could not be found!---\n");
  }
}
