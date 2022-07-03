// --------------------------------------------------------------------------------
// AUTHOR:              Gabriel Coyote
// FILENAME:            Lab3 - Problem 1.c
// SPECIFICATION:       Make a program to assis with calculation of intravenous rates, uses certian functions names: make program with user menu.
// FOR:                 CS 1412 Programming Principles II Section 002 (Tuesday Lab)




#include <stdio.h>
#include <math.h>

//Function Prototypes
int get_problem();

void get_rate_drop_factor(float *rate_ml_hr, float *tubing_drop_factor);
void get_kg_rate_conc(float *rate_mg_kg_hr, float *patient_weight, float *concentration_mg_ml);
void get_units_conc(float *rate_units_per_hr, float *concentration_units_per_ml);

float fig_drops_min(float rate, float drop_factor);
float fig_ml_hr(float num_hrs);
float by_weight(float rate_mg_kg_hr, float patient_weight, float concentration_mg_ml);
float by_units(float rate_units_per_hour, float concentration_units_per_ml);








//MAIN FUNCTION
int main(void) {

  int problem_number;
  int SENTINEL = 5;

  //Variables declared for Switch
  float rate;                 //Case 1
  float drop_factor;          //Case 1
  float drop_rate_per_minute; //Case 1
  float num_hours;            //Case 2
  float ml_per_hour;          //Case 2 & case 3 & case 4
  float mg_kg_hr;             //Case 3
  float patient_weight;       //Case 3
  float conc_mg_ml;           //Case 3
  float units_per_hour;       //Case 4
  float conc_units_per_ml;    //Case 4

  printf("\nINTRAVENOUS RATE ASSISTANT\n");

  problem_number = get_problem();

//SENTINEL loop: exits if user enters 5 for problem number
  while (problem_number != SENTINEL){

    switch(problem_number){   //Switch used to deal with each problem call functions

      case 1: //Problem Number 1
        get_rate_drop_factor(&rate, &drop_factor);
        drop_rate_per_minute = fig_drops_min(rate, drop_factor);

        printf("The drop rate per minute is %.0f.\n", drop_rate_per_minute);
        break;

      case 2: //Problem Number 2
        printf("Enter number of hours=> ");
        scanf("%f", &rate);
        ml_per_hour = fig_ml_hr(rate);

        printf("The rate in milliliters per hour is %.0f.\n", ml_per_hour);
        break;

      case 3: //Prblem Number 3
        get_kg_rate_conc(&mg_kg_hr, &patient_weight, &conc_mg_ml);
        ml_per_hour = by_weight(mg_kg_hr, patient_weight, conc_mg_ml);


        printf("The rate in milliliters per hour is %.0f.\n", ml_per_hour);
        break;

      case 4: //problem number 4
        get_units_conc(&units_per_hour, &conc_units_per_ml);
        ml_per_hour = by_units(units_per_hour, conc_units_per_ml);

        printf("The rate in milliliteers per hour is %.0f\n", ml_per_hour);
        break;

    }

    problem_number = get_problem();
  }
  return 0;
}






// NAME:              get_problem
// INPUT PARAMETERS:  No Input Parameters
// OUTPUT:            Returns an integer
// PURPOSE:           To get user input to decide which of the 4 problems to work with.
int get_problem(){

  int problem_selected;

  printf("\nEnter the number of the problem you wish to solve.\n");
  printf("  GIVEN A MEDICAL ORDER IN                  CALCULATE RATE IN\n");
  printf("(1) ml/hr & tubing drop factor              drops / min\n");
  printf("(2) 1 L for n hr                            ml / hr\n");
  printf("(3) mg/kg/hr & concentration in mg/ml       ml / hr\n");
  printf("(4) units/hr & concentration in units/ml    ml / hr\n");
  printf("(5) QUIT");

  printf("\n\nProblem=> ");
  scanf("%d", &problem_selected);

  return problem_selected;
}






// NAME:              get_rate_drop_factor
// INPUT PARAMETERS:  float pointer: rate milliliteers per hour & float pointer: tubing_drop_factor
// OUTPUT:            Sends data back as output parameters
// PURPOSE:           To get user input for ml/hr and tubing drop factor and to send it back as output parameters
void get_rate_drop_factor(float *rate_ml_hr, float *tubing_drop_factor){

  printf("Enter rate in ml/hr=> ");
  scanf("%f", rate_ml_hr);
  printf("Enter tubing's drop factor(drops/ml)=> ");
  scanf("%f", tubing_drop_factor);

}





// NAME:              get_kg_rate_conc
// INPUT PARAMETERS:  3 float pointers: mg/kg/he & patient weight & mg/ml
// OUTPUT:            Sends data back as output parameters
// PURPOSE:           To get user input for mg/kg/hr & patient weight & mg/ml and send it back as output parameters
void get_kg_rate_conc(float *rate_mg_kg_hr, float *patient_weight, float *concentration_mg_ml){

  printf("Enter rate in mg/kg/hr=> ");
  scanf("%f", rate_mg_kg_hr);
  printf("Enter patient weight in kg=> ");
  scanf("%f", patient_weight);
  printf("Enter concentration in mg/ml=> ");
  scanf("%f", concentration_mg_ml);

}






// NAME:              get_units_conc
// INPUT PARAMETERS:  2 float pointer: units/hour & units/ml
// OUTPUT:            sends data back as output parameters
// PURPOSE:           To get user input for units/hour and units/ml, then sending the data back as output parameters
void get_units_conc(float *rate_units_per_hr, float *concentration_units_per_ml){

  printf("Enter rate in units/hr=> ");
  scanf("%f", rate_units_per_hr);
  printf("Enter concentration in units/ml=> ");
  scanf("%f", concentration_units_per_ml);

}





// NAME:              fig_drops_min
// INPUT PARAMETERS:  2 floats: rate and drop_factor
// OUTPUT:            Returns rounded drops per min as a float
// PURPOSE:           To calculate drops per min based on rate an drop factor, then returning it as a float.
float fig_drops_min(float rate, float drop_factor){

  float drops_per_min;

  drops_per_min = ((rate/60) * drop_factor);

  return roundf(drops_per_min);
}




// NAME:              fig_ml_hr
// INPUT PARAMETERS:  float: number of hours
// OUTPUT:            Returns rounded float of ml per hour
// PURPOSE:           Calculates ml per hour given number of hours, and then returns it as a rounded float.
float fig_ml_hr(float num_hrs){

  float ml_per_hour;

  ml_per_hour = (1000 / num_hrs);

  return roundf(ml_per_hour);
}





// NAME:              by_weight
// INPUT PARAMETERS:  3 floats: mg/kg/hr and patient weight and mg/ml
// OUTPUT:            Returns rounded ml per hour as a float
// PURPOSE:           Calculates ml per hour given mg/kg/he & patient weight & mg/ml, then returning it as a rounded float
float by_weight(float rate_mg_kg_hr, float patient_weight, float concentration_mg_ml){

  float ml_per_hour;

  ml_per_hour = (rate_mg_kg_hr / (concentration_mg_ml / patient_weight));

  return roundf(ml_per_hour);
}




// NAME:              by_units
// INPUT PARAMETERS:  2 floats: units/hour & units/ml
// OUTPUT:            Returns rounded float of ml per hour
// PURPOSE:           Calculates ml per hour given units per hour and units per ml, then returning it as a rounded float.
float by_units(float rate_units_per_hour, float concentration_units_per_ml){

  float ml_per_hour;

  ml_per_hour = (rate_units_per_hour / concentration_units_per_ml );

  return roundf(ml_per_hour);
}
