#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){

    pid_t p1 = fork();
    pid_t p2 = 1;
    if(p1 > 0) p2 = fork();

    int fd[2];

    if(pipe(fd) < 0){
        printf("Pipe error");
        return 1;
    }

    if(p1 < 0 || p2 < 0){
        printf("Fork error");
        return 1;
    }

    if(p1 > 0 && p2 > 0) {

        close(fd[0]);

        write(fd[1], &p2, sizeof(pid_t));
        close(fd[1]);

        int p2_status;

        printf("Main process waits for changing of status of second children\n");
        waitpid(p2, &p2_status, 0);
        printf("Second children was stopped by first one\n");
    }

    if(p1 == 0) {
        close(fd[1]);

        pid_t a;
        read(fd[0], &a, sizeof(pid_t));
        close(fd[0]);

        printf("First children now have got PID of second one\n");
        sleep(10);
        printf("Killing second children\n");
        kill(p2, SIGSTOP);
        exit(0);
    }

    if(p2 == 0){
        while(1) sleep(1);
    }
    return 0;
}