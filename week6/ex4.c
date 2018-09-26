#include <stdio.h>
#include <signal.h>

void sigstop_handler(int sig){
    printf("There was a stop signal\n");
    exit(128+sig);
}

void sigkill_handler(int sig){
    printf("There was a kill signal\n");
    exit(128+sig);
}

void sigusr1_handler(int sig){
    printf("There was a usr1 signal\n");
    exit(128+sig);
}

int main(){

    signal(SIGKILL, sigkill_handler);
    signal(SIGSTOP, sigstop_handler);
    signal(SIGUSR1, sigusr1_handler);
    while(1) {
        sleep(10);
    }
}