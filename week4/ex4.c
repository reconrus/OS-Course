#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char** split(char* str){

    char **args= (char**)malloc(256 * (sizeof(char*)));
    int iter = 0;
    char *token = strtok(str, " \n,");

    while(token != NULL)
    {
        args[iter] = token;
        token = strtok(NULL, " ");
        iter++;
    }

    args[iter] = NULL;
    return args;
}

void execute(char ** args){
   int pid = fork();
   extern char** environ;
   if(pid == 0){
	execvp(args[0], args);
	_exit(0);
   }	
   else{
	int status;
   	do{
	   status = waitpid(pid, &status, WNOHANG);
	}while(!WIFEXITED(status));

   }
}

int main(){
    char *cmd = " ";
    size_t len = 0;
    while(1){
        printf(">");
        getline(&cmd, &len, stdin);
        char** args = split(cmd);
	execute(args);
	free(args);
    }

    return 0;
}


