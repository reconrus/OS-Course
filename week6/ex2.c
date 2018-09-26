#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){

    int fd[2];
    char* s1 = "Some string";
    char s2[13];

    if(pipe(fd) == -1){
        printf("Pipe error");
        return 1;
    }

    pid_t p = fork();

    if(p < 0){
        printf("Fork error");
        return 1;
    }

    if(p > 0) {
        close(fd[0]);
        write(fd[1], s1, strlen(s1));
        close(fd[1]);
    }

    if(p == 0) {
        close(fd[1]);
        read(fd[0], s2, 13);
        close(fd[0]);
        printf("Child process says: %s", s2);
        exit(0);
    }

    return 0;
}