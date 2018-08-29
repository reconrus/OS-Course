#include <stdio.h>

void printStars(int n);
void printSpace(int n);

int main(){
    int n;
    printf("%s", "Enter a height: ");
    scanf("%d", &n);

    for(int i = n; i >= 0; i--){
        int j = i/2;
        printSpace(i);
        printStars(2*(n - i) - 1);
        putchar('\n');

    }
}

void printStars(int n){
    for(int i = 0; i < n; i++) putchar('*');
}

void printSpace(int n){
    for(int i=0; i<n; i++) putchar(' ');
}