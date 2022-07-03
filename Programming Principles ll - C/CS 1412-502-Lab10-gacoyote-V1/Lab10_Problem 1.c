// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab10_Problem 1.c
// SPECIFICATION:       Make a program to read a person's information into a structure, and then read out the information. Also a program that Calculates other health related information to be printed out.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)

#include <stdio.h>


//STRUCTURE "Date of Birth" for a person
typedef struct {

  int month;
  int day;
  int birth_year;

} dob_t;

//STRUCTURE "Starter" HealthProfile for a person
typedef struct {

  char first_name[30];
  char last_name[30];
  char gender[20];

  dob_t date_of_birth;

  float height_cm;
  float weight_kg;

} HealthProfile_t;



//FUNCTION PROTOTYPES
void read_data(HealthProfile_t *person);
void print_data(HealthProfile_t *person);
void calc_data(HealthProfile_t *person, int *age_years, float *BMI, int *max_heart_rate, int *target_HR1, int *target_HR2);



//MAIN FUNCTION
int main(void) {
 
  HealthProfile_t person;

  read_data(&person);
  print_data(&person);


  return 0;
}




// NAME:              read_data
// INPUT PARAMETERS:  A structure variable pointer; 'person'
// OUTPUT:            Prompts users for information, scans information into their respected variables within the "person"'s HealthProfile_t structure.
// PURPOSE:           The functions purpose is to read information from user to store into the HealthProfile_t structure
void read_data(HealthProfile_t *person){
  printf("Enter First Name: ");
  scanf(" %s", person->first_name);
  printf("Enter Last Name: ");
  scanf(" %s", person->last_name);
  printf("Enter Gender: ");
  scanf(" %s", person->gender);
  printf("Enter Date of Birth (mm dd yyyy): ");
  scanf(" %d %d %d", &person->date_of_birth.month,&person->date_of_birth.day, &person->date_of_birth.birth_year);

  printf("Enter Height (Centimeters): ");
  scanf(" %f", &person->height_cm);
  printf("Enter Weight (Kilograms): ");
  scanf(" %f", &person->weight_kg);
}



// NAME:              print_data
// INPUT PARAMETERS:  A structure variable pointer: 'person'
// OUTPUT:            No Rturns; Prints out inputted information along with calculated health information. 
// PURPOSE:           The functions purpose is to print out the "profile information" of the person in the structure "HealthProfile", uses another function (calc_data) to help calculate other health information to be printed. 

void print_data(HealthProfile_t *person){
  printf("\n\nProfile Infromation\n");
  printf("__________________________");

  printf("\nFirst Name: %s", person->first_name);
  printf("\nLast Name: %s", person->last_name);
  printf("\nGender: %s", person->gender);
  printf("\nDate of Birth: %d/%d/%d", person->date_of_birth.month,person->date_of_birth.day, person->date_of_birth.birth_year);
  printf("\nHeight (Centimeters): %.1f", person->height_cm);
  printf("\nWeight (Kilograms): %.1f", person->weight_kg); 
  
  int age_years;
  int max_heart_rate;
  float BMI;
  int target_HR1, target_HR2; //Your ranger for target heart rate, HR1 = Floor; HR2 = Max

  //Calculates the age in years, BMI, max HR, Target HR and returns as an OUTPUT PARAMETER
  calc_data( person, &age_years, &BMI, &max_heart_rate, &target_HR1, &target_HR2);

  printf("\n\nAge in Years: %d", age_years);
  printf("\nBMI: %.1f", BMI);
  printf("\nMax Heart Rate: %d", max_heart_rate);
  printf("\nTarget Heart Rate Range: %.0d - %.0d bpm", target_HR1, target_HR2);

  //BMI Chart
  printf("\n\nBMI VALUES");
  printf("\nUnderweight: less than 18.5");
  printf("\nNormal:      between 18.5 and 24.9");
  printf("\nOverweight:  between 25 and 29.9");
  printf("\nObese:       30 or greater\n");

}


// NAME:              calc_data
// INPUT PARAMETERS:  A structure variable pointer: 'person'
//                    A integer Pointer: "age_years" and "max_heart_rate" and "target_HR1" and "target_HR2"
//                    A float Pointer: "BMI"
// OUTPUT:            No Returns; Has output parameters for age_years, BMI, max_heart_rate, target heart range value 1 and 2.  
// PURPOSE:           The functions purpose is to calculate the person's age in years, BMI, Max heart rate, and Target heart rate range. It returns these values as output parameters.

void calc_data(HealthProfile_t *person, int *age_years, float *BMI, int *max_heart_rate, int *target_HR1, int *target_HR2){

  *age_years = (2020-(person->date_of_birth.birth_year));
  *BMI = ((person->weight_kg) / (((person->height_cm)/100)*2));
  *max_heart_rate = (220 - *age_years);

  //"IF Else" To calculate target heart rate range; based off age_years CLOSEST to Age Category in the Chart given
 if (*age_years <= 24){
    *target_HR1 = 100;
    *target_HR2 = 170; //ages 0 -20
  } else if (*age_years <=32){
    *target_HR1 = 95;
    *target_HR2 = 162;//Ages closest to 30 years
  } else if (*age_years <= 37){
    *target_HR1 = 93;
    *target_HR2 = 157;//Ages closest to 35 years
  } else if ( *age_years <=42){
    *target_HR1 = 90;
    *target_HR2 = 153;//Ages closest to 40 years
  }else if (*age_years <=47){
    *target_HR1 = 88;
    *target_HR2 = 149;//Ages closest to 45 years
  } else if (*age_years <=52){
    *target_HR1 = 85;
    *target_HR2 = 145; //Ages closest to 50 years
  } else if (*age_years <=57){
    *target_HR1 = 83;
    *target_HR2 = 140;//Ages closest to 55 years
  } else if (*age_years <=62){
    *target_HR1 = 80;
    *target_HR2 = 136; //Ages closest to 60 years
  }else if (*age_years <=67){
    *target_HR1 = 78;
    *target_HR2 = 132;//Ages closest to 65 years
  } else if (68 <= *age_years){
    *target_HR1 = 75;
    *target_HR2 = 128; //Ages closest/greater to 70 years
  } else{
    printf("\nERROR: Enter Valid Formatted Birth Year");
  }

}