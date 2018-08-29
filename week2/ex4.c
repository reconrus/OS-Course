#include <stdio.h>

int main(){
    int a, b;
    printf("%s", "Enter numbers: ");
    scanf("%d%d", &a, &b);

    swap(&a, &b);
    printf("%s%d%s%d", "\nNow first one: ", a, "\nSecond: ", b);
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}