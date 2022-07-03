// Gabriel Coyote
// CS 4352 - Operating System

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char* argv[]){

  //pid_t pid;
  char *num_child_process = argv[1];
  int N = atoi(num_child_process);


  // Creating CHAIN of childs for Part 2 - second half
  int i;
  for(i = 0; i < N; i++){ //************************************

    pid_t pid = fork();


    if(pid < 0){
      // Fork/Child creation was UN-succesfull
      printf("\n[ERROR]: Fork/Child creation failed...");
    }


    if(pid > 0){
      // Parent Process run these lines of code
      wait(NULL); // Our Parent Process
      break; // Break out of FOR loop so this current process won't create another child
    }


    else{
      // Child Process run these lines of code
      printf("\nHello! My process PID is: %d ... My Parent's PID: %d", getpid(), getppid());
      fflush(NULL); //Flushing buffer after printing
    }
  }//************************************



  return 0;
}
