#include <stdio.h>
#include <stddef.h>

void bubble_sort(int *a, size_t n){

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n - 1; j++)
            if(a[j] > a[j+1]){
                int c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
            }
}
