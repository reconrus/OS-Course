#include <stdio.h>
#include <sys/types.h>

int main(){
  int n = 15;
  int pid = fork();
  
  switch(pid){
   case -1: printf("Error occured");
	break;
   case 0: printf("Hello from child [%d - %d]\n", pid, n);
        break;
   default: printf("Hello from parent [%d - %d]\n", pid, n);
  }

  return 0;
}
