#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "scheduling.h"





// NAME:              scan_store_crew_data
// INPUT PARAMETERS:  No Input PARAMETERS
// OUTPUT:            Prompts users for information, scans information into their respected variables within the crew member's data STRUCTURE
// PURPOSE:           The functions purpose is to read information from user to store the name of crew members and their crew number; assigns skill level automatically based of crew number.
void scan_store_crew_data(){
  int flag = 0;
  int flag_2 = 0;
  int Number_of_Crew_members;

  //Checks for non numerical inputs
  printf("\nEnter the number of crew members being stored: ");
  do{ 
    char c = getchar();//Read wahts in the stdin
    if (isdigit(c)){
      ungetc(c, stdin);//returning digit back
      flag = scanf("%d", &Number_of_Crew_members);
    } else{
      printf("\nInvalid Input - Try Again: ");//Prints out twice if character is entered; weird
    }
  } while(flag == 0 || Number_of_Crew_members == 0);

  //Declare array to hold members data
  crew_data_t Crew_Members[Number_of_Crew_members];

  //Input Data for each crew member
  for(int i = 0; i < Number_of_Crew_members; i++){
    printf("\nEnter [%d] Member Name:", i);
    scanf("%s", Crew_Members[i].name);
    
    //Chechks for number out of range; bugs out if character is entered
    do{
      printf("Enter [%d] Member's crew number(0-2): ", i);
      flag_2 = scanf("%d", &Crew_Members[i].skill_level);
      if (Crew_Members[i].skill_level<0 || Crew_Members[i].skill_level>2){
        printf("\nOut of Range Integer-Try again: \n");
      }
    } while (flag_2 == 1 && (Crew_Members[i].skill_level<0 || Crew_Members[i].skill_level>2));
    
    //Assign skill level based on crew number
    if(Crew_Members[i].crew_num == 0){
      Crew_Members[i].skill_level =1;
    } else if(Crew_Members[i].crew_num == 1){
      Crew_Members[i].skill_level = 2;
    } else if(Crew_Members[i].crew_num == 2){
      Crew_Members[i].skill_level = 3;
    } else{
      printf("\n----Invalid Crew Number! Please Restart the Program!");
    }
  }
  
}







// NAME:              scan_store_maintenance_data
// INPUT PARAMETERS:  No Input PARAMETERS
// OUTPUT:            Returns NUmber of Aircrafts Needing maintenance; Prompts users for information, scans information into their respected variables within the maintenanceData_t STRUCTURE
// PURPOSE:           The functions purpose is to read information from user to store the ID of aircrafts needing maintence into the maintenanceData_t STRUCTURE; automatically assigns level of maintenace and number of hours to each aircraft based off Aircraft ID
int scan_store_maintenance_data(){
  int flag = 0;
  int flag_2 = 0;
  int Number_of_Aircrafts;

  //Chechks for non numerical inputs
  printf("\n\nEnter the number of Aircrafts needing work: ");
  do{ 
    char c = getchar();//Read wahts in the stdin
    if (isdigit(c)){
      ungetc(c, stdin);//returning digit back
      flag = scanf(" %d", &Number_of_Aircrafts);
    } else {
      printf("\nIf Invalid - Will reprompt: ");//Prints out twice if character is entered; weird
    }
  } while(flag == 0 || Number_of_Aircrafts == 0);

  //Declare array to hold Aircrafts data
  maintenanceData_t Aircrafts[Number_of_Aircrafts];

  //Input Data for each crew member
  //Repeats if invalid Aircraft ID is entered; inputting a character needs a error message 
  for(int i = 0; i < Number_of_Aircrafts; i++){
    printf("\nEnter Aircraft #%d ID:", i);
    do{
      printf("\nIf Invalid - Will reprompt:");
      flag_2 = scanf("%d", Aircrafts[i].ID);
    } while (flag_2 == 0 || ((*Aircrafts[i].ID != 7899) && (*Aircrafts[i].ID != 3119) && (*Aircrafts[i].ID != 7668) && (*Aircrafts[i].ID != 2324) && (*Aircrafts[i].ID != 1123) && (*Aircrafts[i].ID != 7555) && (*Aircrafts[i].ID != 6789) && (*Aircrafts[i].ID != 7888)));

    //Assign level of maintence and number of hours to each aircraft based off ID NUMBER
    switch (*Aircrafts[i].ID){
      case 7899:
        Aircrafts[i].Number_of_hours = 8;
        Aircrafts[i].Maintenance_level = 1;
        break;
      case 3119:
       Aircrafts[i].Number_of_hours = 6;
       Aircrafts[i].Maintenance_level = 1;
       break;
      case 7668:
       Aircrafts[i].Number_of_hours = 4;
       Aircrafts[i].Maintenance_level = 1;
       break;
      case 2324:
       Aircrafts[i].Number_of_hours = 4;
       Aircrafts[i].Maintenance_level = 2;
       break;
      case 1123:
       Aircrafts[i].Number_of_hours = 8;
       Aircrafts[i].Maintenance_level = 2;
       break;
      case 7555:
       Aircrafts[i].Number_of_hours = 4;
       Aircrafts[i].Maintenance_level = 2;
       break;
      case 6789:
       Aircrafts[i].Number_of_hours = 2;
       Aircrafts[i].Maintenance_level = 3;
       break;
      case 7888:
       Aircrafts[i].Number_of_hours = 10;
       Aircrafts[i].Maintenance_level = 3;
       break;
      default:
        printf("Invalid ID; Please restart the program!");
        break;
    }
  }
  return Number_of_Aircrafts;
}








// NAME:              num_lowest_cost_crew(maintenanceData_t *Aircraft[], crew_data_t *crew, int Number_of_Aircrafts)
// INPUT PARAMETERS:  Array Pointer to Struccture; Pointer to Struccture; and Integer Number_of_Aircrafts
// OUTPUT:            Returns Lowest crew number required to perform maintenace;
// PURPOSE:           The functions purpose is to return the lowest cost crew that can perform the maintenance; 
int num_lowest_cost_crew(maintenanceData_t *Aircraft[], crew_data_t *crew, int Number_of_Aircrafts){
  int lowest_crew_num;

 //Didn't finish
//This Lab was harder than I expected!

  return lowest_crew_num;
}