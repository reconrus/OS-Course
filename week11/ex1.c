#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(){
    int fd;
    void* dst;
    struct stat _stat;
    if((fd = open("/home/coolhawk/CLionProjects/untitled/ex1.txt", O_RDWR)) < 0) {
        printf("Cannot open ex1.txt\n");
        exit(1);
    }

    stat("/home/coolhawk/CLionProjects/untitled/ex1.txt", &_stat);

    if((dst = mmap(NULL, _stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)) == MAP_FAILED){
        printf("mmap error\n");
        exit(1);
    }

    char* src = "This is a nice day";
    char* space = " ";
    size_t str_size = 18;
    ftruncate(fd, str_size);
    memcpy(dst, src, str_size);

    return 0;
}