/*
Gabriel Coyote
CS 4352: OS - Project 2


This project2.c file contains
  - Source codes for requirements #1, #2, and #3
  - Shorthand notation of commands
    . -name    ->   -n
    . -mmin    ->   -m
    . -inum    ->   -i
    . -delete  ->   -d

  - Using 'makefile' provided; compiles to...
    . Program Name:  'finder'

  - Test run example...
    . './finder testdir -n test5 -d'

*/







#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
char * full_path;








/* *********************************************************** */

// Print all subdirectory/files within a given Directory
void read_sub(char* sub_dir){

  DIR *sub_dp = opendir(sub_dir);   // Open a directory stream
  struct dirent * sub_dirp;        // Define


  // Check whether the Directory stream is opened successfully
  if(sub_dp!=NULL){

      // Red one entyry each time
       while((sub_dirp = readdir(sub_dp)) != NULL){

         // Check whether the first entry is a subdirectory
	       char * temp = sub_dirp->d_name;
         char temp1[]= ".";
         char temp2[]= "..";

         // To avoid recursively searching . and .. in the directory. //recurcively loop into the sub-directory
        if(strcmp(temp,temp1)!=0 && strcmp(temp,temp2)!=0){

          char temp3[] = "/";

          char *temp_sub = temp3;
	        temp_sub = strcat(temp_sub,temp);  // Now you add the '/' in front of the entry's name


	        char * temp_full_path = malloc(sizeof(char)*2000);
	        temp_full_path = strcpy(temp_full_path,sub_dir);

	         strcat(temp_full_path,temp_sub); // Now you get a full path, e.g, 'testdir/dir1'   OR  'testdir/test1'
 	         DIR * subsubdp = opendir(temp_full_path);  // Try to open
           printf("%s\n",temp_full_path );

            // If not NULL, it means that we found a subdirectory; otherwise its just a file
	          if(subsubdp != NULL){
	             closedir(subsubdp);         // Close the stram, becuase we will reopen it in the recursive call.
               read_sub(temp_full_path);    // Call the recursive function call
             }

           } // End of IF statement near line ~37


         } // End of WHILE loop
         closedir(sub_dp);  // Close the stream





  } else {
        printf("Read_Sub: cannot open directory\n");
        exit(2);
    }

}


/* *********************************************************** */
// Print all subdirectory/files within a given Directory that
// contains a specific file name
void read_sub_findName(char* sub_dir, char* name, int delete){

  DIR *sub_dp = opendir(sub_dir);   // Open a directory stream
  struct dirent * sub_dirp;      // Define



  // Check whether the directory stream is opened successfully
  if(sub_dp != NULL){


      // Red one entyry each time
       while((sub_dirp = readdir(sub_dp)) != NULL){

         // Check whether the first entry is a subdirectory
	       char * temp = sub_dirp->d_name;
         char temp1[]= ".";
         char temp2[]= "..";

         // To avoid recursively searching . and .. in the directory. //recurcively loop into the sub-directory
        if(strcmp(temp,temp1)!=0 && strcmp(temp,temp2)!=0){

          char temp3[] = "/";

          char *temp_sub = temp3;
	        temp_sub = strcat(temp_sub,temp);  // Now you add the '/' in front of the entry's name


	        char * temp_full_path = malloc(sizeof(char)*2000);
	        temp_full_path = strcpy(temp_full_path,sub_dir);

	         strcat(temp_full_path,temp_sub); // Now you get a full path, e.g, 'testdir/dir1'   OR  'testdir/test1'
 	         DIR * subsubdp = opendir(temp_full_path);  // Try to open


              /* ************************* deleting *************************** */

           // If current file/directory equals name to search for; print it out
            if( (strcmp(temp, name) == 0) && (delete == 0)){
              // Delete is set to 0;    don't delete
              printf("%s\n", temp_full_path);



            } else if( (strcmp(temp, name) == 0) && (delete == 1)){
              // Delete is set to 1;    so delete
              printf("\tDeleting file: %s \n", temp);



              int success;
              success = remove(temp_full_path);

              if(success == 0){
                printf("\tFile deleted successfully \n");
              } else {
                printf("\tError: unable to delete the file \nCould be a directory!!!");
              }



            }


            /* ************************* deleting *************************** */


            // If not NULL, it means that we found a subdirectory; otherwise its just a file
	          if(subsubdp != NULL){
	             closedir(subsubdp);      // Close the stram, becuase we will reopen it in the recursive call.
               read_sub_findName(temp_full_path, name, delete);    // Call the recursive function call
             }


           } // End of IF statement near Line ~ 97


         } // End of WHILE loop
         closedir(sub_dp);  // Close the stream





  } else {
        printf("FindName: cannot open directory\n");
        exit(2);
    }

}


/* *********************************************************** */
// Print all subdirectory/files within a given Directory that
// was modified with 'min' minutes ago
void read_sub_Mmin(char* sub_dir, char option, int minutes, int delete){

  DIR *sub_dp = opendir(sub_dir);   // Open a directory stream
  struct dirent * sub_dirp;      // Define
  struct stat stats;        // Define a file status structure



  // Check whether the directory stream is opened successfully
  if(sub_dp != NULL){


      // Red one entyry each time
       while((sub_dirp = readdir(sub_dp)) != NULL){

         // Check whether the first entry is a subdirectory
	       char * temp = sub_dirp->d_name;
         char temp1[]= ".";
         char temp2[]= "..";

         // To avoid recursively searching . and .. in the directory. //recurcively loop into the sub-directory
        if(strcmp(temp,temp1)!=0 && strcmp(temp,temp2)!=0){

          char temp3[] = "/";

          char *temp_sub = temp3;
	        temp_sub = strcat(temp_sub,temp);  // Now you add the '/' in front of the entry's name


	        char * temp_full_path = malloc(sizeof(char)*2000);
	        temp_full_path = strcpy(temp_full_path,sub_dir);

	         strcat(temp_full_path,temp_sub); // Now you get a full path, e.g, 'testdir/dir1'   OR  'testdir/test1'
 	         DIR * subsubdp = opendir(temp_full_path);  // Try to open


            /* ************************* deleting *************************** */
           // Get this file or Directory STATS
           if( stat(temp_full_path, &stats) == 0){

             int modified_mins_ago = 0;
             double seconds_diff = 0;
             time_t currentTime;   // Define, initialize
             time( &currentTime ); // Get current time

             seconds_diff = difftime( currentTime, stats.st_mtime);
             modified_mins_ago = (int) (seconds_diff / 60);

             switch (option) {
               case '-':


                  if( (modified_mins_ago < minutes) &&  (delete == 0) ){
                    printf("%s\n", temp_full_path );

                  } else if( (modified_mins_ago < minutes) &&  (delete == 1) ){

                    // Delete file(s)
                    /* ***************************** */
                   // delete is set to 1; delete
                   printf("Deleting file: %s \n", temp);

                   int success;
                   success = remove(temp_full_path);

                   if(success == 0) { printf("File deleted successfully \n");
                 } else { printf("Error: unable to delete the file \nCould be a directory!!!"); }

                   /* ***************************** */


                  }// end of else if statement


                  break;
               case '+':

                  if( (modified_mins_ago > minutes) &&  (delete == 0) ){
                    printf("%s\n", temp_full_path );

                  } else if( (modified_mins_ago < minutes) &&  (delete == 1) ){

                    // Delete file(s)
                    /* ***************************** */
                   // delete is set to 1; delete
                   printf("Deleting file: %s \n", temp);

                   int success;
                   success = remove(temp_full_path);

                   if(success == 0) { printf("File deleted successfully \n");
                 } else { printf("Error: unable to delete the file \nCould be a directory!!!"); }

                   /* ***************************** */


                  }// end of else if statement


                  break;
               case '=':

                  if( (modified_mins_ago == minutes) &&  (delete == 0) ){
                    printf("%s\n", temp_full_path );

                  } else if( (modified_mins_ago < minutes) &&  (delete == 1) ){

                    // Delete file(s)
                    /* ***************************** */
                   // delete is set to 1; delete
                   printf("Deleting file: %s \n", temp);

                   int success;
                   success = remove(temp_full_path);

                   if(success == 0) { printf("File deleted successfully \n");
                 } else { printf("Error: unable to delete the file \nCould be a directory!!!"); }

                   /* ***************************** */


                 } // end of else if statement



                  break;
               default:
                  printf("[MMIN ERROR]\n" );
                  break;
             }
           }

            /* ************************* deleting *************************** */


            // If not NULL, it means that we found a subdirectory; otherwise its just a file
	          if(subsubdp != NULL){
	             closedir(subsubdp);      // Close the stram, becuase we will reopen it in the recursive call.
               read_sub_Mmin(temp_full_path, option, minutes, delete);    // Call the recursive function call
             }


           } // End of IF statement near Line ~ 97


         } // End of WHILE loop
         closedir(sub_dp);  // Close the stream





  } else {
        printf("Mmin: cannot open directory\n");
        exit(2);
    }

}


/* *********************************************************** */
// Print all subdirectory/files within a given Directory that
// contains a specified i-node number
void read_sub_inum(char* sub_dir, int node_num, int delete){

  DIR *sub_dp = opendir(sub_dir);   // Open a directory stream
  struct dirent * sub_dirp;      // Define
  struct stat stats;        // Define a file status structure



  // Check whether the directory stream is opened successfully
  if(sub_dp != NULL){


      // Red one entyry each time
       while((sub_dirp = readdir(sub_dp)) != NULL){

         // Check whether the first entry is a subdirectory
	       char * temp = sub_dirp->d_name;
         char temp1[]= ".";
         char temp2[]= "..";

         // To avoid recursively searching . and .. in the directory. //recurcively loop into the sub-directory
        if(strcmp(temp,temp1)!=0 && strcmp(temp,temp2)!=0){

          char temp3[] = "/";

          char *temp_sub = temp3;
	        temp_sub = strcat(temp_sub,temp);  // Now you add the '/' in front of the entry's name

	        char * temp_full_path = malloc(sizeof(char)*2000);
	        temp_full_path = strcpy(temp_full_path,sub_dir);

	         strcat(temp_full_path,temp_sub); // Now you get a full path, e.g, 'testdir/dir1'   OR  'testdir/test1'
 	         DIR * subsubdp = opendir(temp_full_path);  // Try to open


            // Get this file or Directory stats
            if(stat(temp_full_path, &stats) == 0){

            /* ************************* deleting *************************** */

              // If this current stats inode num match; print directory
              if( (node_num == (int)stats.st_ino) && delete == 0 ){
                printf("%s\n", temp_full_path );


              } else if( (node_num == (int)stats.st_ino) && delete == 1 ){
                // Delete is set to 1;    so delete
                printf("\tDeleting file: %s \n", temp);


                /* **************** deleting ************* */
                int success;
                success = remove(temp_full_path);

                if(success == 0){
                  printf("\tFile deleted successfully \n");
                } else {
                  printf("\tError: unable to delete the file \nCould be a directory!!!");
                }
                /* **************** deleting ************* */

              } // end of else if statement

            /* ************************* deleting *************************** */

            } // end of if stats statement


            // If not NULL, it means that we found a subdirectory; otherwise its just a file
	          if(subsubdp != NULL){
	             closedir(subsubdp);      // Close the stram, becuase we will reopen it in the recursive call.
               read_sub_inum(temp_full, node_num, delete);    // Call the recursive function call
             }


           } // End of IF statement near Line ~ 97


         } // End of WHILE loop
         closedir(sub_dp);  // Close the stream





  } else {
        printf("inum: cannot open directory\n");
        exit(2);
    }

}



/* *********************************************************** */
/* *********************************************************** */











/* *********************************************************** */
void find(char *where, char *name, char *action){
  /* Test arguments parsed. */
  printf("find %s %s %s\n", where, name, action);
}


void findName(char *dir, char *name, int delete){
  read_sub_findName(dir, name, delete);
}


void findMmin(char *dir, char *min, int delete){

  int minutes;
  char option;  // '-' || '+' || '='

  // Look at first char: '-' || '+' || number
  option = min[0];

  switch (option) {
    case '-':
      // Look for modified files modified less than 'minutes' ago
      option = '-';
      minutes = atoi(min) * -1; // to correct conversion; neg -> pos
      break;

    case '+':
      // Look for modified files modified greater than 'minutes' ago
      option = '+';
      minutes = atoi(min);
      break;


    default:
      // Look for modified files modified  exactly 'minutes' ago
      option = '=';
      minutes = atoi(min);
      break;
  }


  read_sub_Mmin(dir, option, minutes, delete);
}


void findInum(char *dir, char *inum, int delete){
  // Convert the string i-node number to int
  int node_num = atoi(inum);
  read_sub_inum(dir, node_num, delete);
}





/* **********************************************************
 *                    MAIN FUNCTION                         *
 ************************************************************/
int main(int argc, char **argv){

    // INT argc: Number of parameters
    // CHAR argv: String of parameter

    // Char Pointer holding directory name
    char * dir;


    if(argc < 2){
       // If no directory & command specified,
       // Set to current directory & Read directory
      dir = ".";
      read_sub(dir);

    } else if(argc == 2) {
      // If only directory name provided, print directory content
      dir = argv[1];
      read_sub(dir);

    } else{

      // Else use specified Directory, and parse commands
      dir = argv[1];
      argc -= optind;
      argv += optind;




    // Used in Switch case
    // Int(s)   -   equal to 1; if given corresponding commands
    // Char*    -   to hold name of parsed arguments
    int w, n, m, i, a, delete;
    w = 0; n = 0; m = 0; i = 0; a = 0, delete = 0;
    char *where, *name, *mmin, *inum, *action;


    while(1){
      char c;

      // Using getopt() to parse commands; i.e, '-name'  or '-inum'
      c = getopt(argc, argv, "w:n:m:i:a:delete:");

      // Break if we have finished procressing all arguments
      if (c == -1){ break;}

      switch (c) {
        case 'w':
          w = 1;
          where = optarg;
          //printf("[switch] where: %s\n", optarg);
          break;

        case 'n':
          n = 1;
          name = optarg;
          //printf("[switch] name: %s\n", optarg);
          break;

        case 'm':
          m = 1;
          mmin = optarg;
          //printf("[switch] mmin: %s\n", optarg);
          break;


        case 'i':
          i = 1;
          inum = optarg;
          //printf("[switch] inum: %s\n", optarg);
          break;

        case 'a':
          a = 1;
          action = optarg;
          //printf("[switch] action: %s\n", optarg);
          break;

        case 'd':
          delete = 1;
          break;

        case '?':

        default:
          printf("[switch] An invalid option detected.\n" );
      }

    }



    if( w == 0 && n == 0 && m == 0 && i == 0) read_sub( dir );         // Just read current


    // Our criteria w/ delete argument;  delete := 1 to delete || delete := 0 to don't delete
    if( w == 0 && n == 1 ) findName( dir, name, delete);    // Specified directory & filename
    if( w == 0 && m == 1 ) findMmin( dir, mmin, delete);     // Specified directory & mmin := Number(string)
    if( w == 0 && i == 1 ) findInum( dir, inum, delete);     // Specified directory & inum := number(string)


  	 // Now set the values of "argc" and "argv" to the values after the
  	 // options have been processed above.
     argc -= optind;
     argv += optind;


     if (argc > 0) printf("\n[Invalid Command]\n");


    }
    return 0;



}
