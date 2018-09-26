#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){

    pid_t p = fork();

    if(p < 0){
        printf("Fork error");
        return 1;
    }

    if(p > 0) {
        sleep(10);
        kill(p, SIGTERM);
    }

    if(p == 0) {
        while(1){
            printf("I am alive\n");
            sleep(1);
        }
    }
    return 0;
}