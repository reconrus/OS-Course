#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include <malloc.h>
#include <memory.h>

void* my_realloc(void* ptr, size_t size){

    if(ptr == NULL) return malloc(size);
    if(size == 0) {
        free(ptr);
        return NULL;
    }

    void* new_ptr = malloc(size);
    size_t old_size = malloc_usable_size(ptr);
    if (old_size < size)
        memcpy(new_ptr, ptr, old_size);
    else
        memcpy(new_ptr, ptr, old_size);
    free(ptr);
    return new_ptr;
}