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
    int fd_src, fd_dst;
    void *dst, *src;
    struct stat src_stat, dst_stat;
    if((fd_src = open("/home/coolhawk/CLionProjects/untitled/ex1.txt", O_RDWR)) < 0) {
        printf("Cannot open ex1.txt\n");
        exit(1);
    }

    if((fd_dst = open("/home/coolhawk/CLionProjects/untitled/ex1.memcpy.txt", O_CREAT| O_RDWR | O_TRUNC, 0777)) < 0) {
        printf("Cannot open ex1.memcpy.txt\n");
        exit(1);
    }

    fstat(fd_src, &src_stat);
    fstat(fd_dst, &dst_stat);

    size_t size = (size_t)src_stat.st_size;

    if((src = mmap(NULL, size, PROT_READ, MAP_SHARED, fd_src, 0)) == MAP_FAILED){
        printf("src mmap error\n");
        exit(1);
    }

    if((dst = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd_dst, 0)) == MAP_FAILED){
        printf("dst mmap error\n");
        printf("%d", errno);
        exit(1);
    }
    ftruncate(fd_dst, size);
    memcpy(dst, src, size);
    return 0;
}