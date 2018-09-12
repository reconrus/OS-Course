#include <stdio.h>
#include <sys/types.h>

int main(){
  char *cmd;
  size_t len = 0;
  while(1){
    putchar('>');
    getline(&cmd, &len, stdin);
    system(cmd);
  }
  
  return 0;
}
