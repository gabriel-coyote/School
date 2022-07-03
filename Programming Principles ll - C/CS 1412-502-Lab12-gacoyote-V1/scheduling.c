#include <stdio.h>
#include "scheduling.h"


//Simply stores each indivdual crew member's name; crew number; skill level
//Incase the employer wants to pull the member's info.
void scan_store_crew_data(){
  int flag = 1;
  int Number_of_Crew_members;

  //Needs fixing for invaldi input
  printf("Enter the number of crew members being stored: ");
  scanf(" %d", &Number_of_Crew_members);

  //Declare array to hold members data
  crew_data_t Crew_Members[Number_of_Crew_members];

  //Input Data for each crew member
  for(int i = 0; i < Number_of_Crew_members; i++){
    printf("\nEnter Member %d Name:", i);
    scanf("%s", Crew_Members[i].name);
    printf("Enter Member's crew number(0-2): ");
    scanf("%d", &Crew_Members[i].crew_num);

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




//Scans in maintenance work needed to be done
void scan_store_maintenance_data(){
  int input = 0;
  int Number_of_Aircrafts;

  
  printf("Enter the number of Aircrafts needing work: ");
  scanf(" %d", &Number_of_Aircrafts);


  //Declare array to hold Aircrafts data
  maintenanceData_t Aircrafts[Number_of_Aircrafts];

  //Input Data for each crew member
  for(int i = 0; i < Number_of_Aircrafts; i++){
    printf("\nEnter Aircraft #%d ID:", i);
    scanf("%d", Aircrafts[i].ID);

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

}