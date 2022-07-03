
//Structure to hold crew members data (Name, Crew Number, Skill Level)
//Not cost becuase we are assuming cost of per crew per hour stays the same.
typedef struct {
  char name[50];
  int crew_num;
  int skill_level;
}crew_data_t;


//Stores the maintenance work needed to be perform
//Stores the Aircraft ID; Level of Maintenance and number of hours required for it.
typedef struct{
  int ID[4];//Max length of id is 4 integers
  int Maintenance_level;
  int Number_of_hours;
}maintenanceData_t;





//Assuming we ONLY have 3 crew "teams", this function will only store the crew memebers in their respective crews
void scan_store_crew_data(); 

//Scans and stores what needs to be fixed
void scan_store_maintenance_data();

//


