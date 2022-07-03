// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab12_Problem 1.c
// SPECIFICATION:       Write functions and create a scheduling library from them; to use for the Brown Bag Airlines 
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)


#include <stdio.h>
#include "scheduling.h"

//My wifi was out in my area, it went out on wednesday, and i didn't have it fixed till friday morning; I did my best to try to finish the lab
int main(void) {

  maintenanceData_t **Aircrafts;
  crew_data_t *crew;

  int lowest_crew_num_required; 
  int Number_of_Aircrafts;

  scan_store_crew_data();
  Number_of_Aircrafts = scan_store_maintenance_data();

  lowest_crew_num_required = num_lowest_cost_crew(Aircrafts, crew, Number_of_Aircrafts);

  printf("\n%d", lowest_crew_num_required);

//Didn't finish
//This Lab was harder than I expected!
  return 0;
}