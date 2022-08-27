// Gabriel Coyote
// CS 4352 - Operating System

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char* argv[]){

  pid_t pid;
  char *num_child_process = argv[1];
  int N = atoi(num_child_process);


  // Creating MUTIPLE childs for Part 2 - first half
  int i;
  for(i = 0; i < N; i++){ //************************************
    pid = fork();


    if(pid >= 0){//---------------------------------------
      // Fork/Child creation was succesfull
      if(pid == 0){
        // Child Process run these lines of code
        printf("\nHello! My process PID is: %d ... My Parent's PID: %d", getpid(), getppid());
        return 0;
      }else{
        // Parent Process run these lines of code
        wait(NULL); // Wait for termination of child via kill() or return int in child process;
      }

    }else{//---------------------------------------
      // Fork/Child creation was UN-succesfull
      printf("\n[ERROR]: Fork/Child creation failed...");
      return 0;
    }
  }//************************************

  return 0;
}
