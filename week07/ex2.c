#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main(){

    int n = 0;

    printf("Enter number of elements of an array: ");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}