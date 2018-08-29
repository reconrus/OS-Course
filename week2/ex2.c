#include <stdio.h>
#include <memory.h>

int main(){
    char s[1000];
    printf("%s", "Enter a string: ");
    scanf("%s", s);
    int len = strlen(s);

    for(int i = len-1; i >= 0; i--){
        putchar(s[i]);
    }
}