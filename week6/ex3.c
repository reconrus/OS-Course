#include <stdio.h>
#include <signal.h>
void handler(int sig){
    printf("There was an interrupt signal\n");
    exit(128 + SIGINT); //I am not sure about exit code
}

int main(){
    signal(SIGINT, handler);
    while(1) {
        sleep(10);
    }
}