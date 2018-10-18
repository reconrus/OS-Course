#include <stdio.h>
#include <stdlib.h>

typedef struct _frame{
    unsigned int page_number;
    unsigned char aging;
} Frame;

int find_page(unsigned int page, int number_of_frames, Frame* page_frames){
    int current_index;

    for (current_index = 0; current_index < number_of_frames; current_index++) {
        if (page_frames[current_index].page_number == page) {
            break;
        }
    }

    return current_index == number_of_frames? -1 : current_index;
}

void page_replacement(unsigned int current_page, int number_of_frames, Frame* page_frames){
    unsigned int min_aging_index = 0;

    for (unsigned int i = 1; i < number_of_frames; i++)
        if (page_frames[i].aging < page_frames[min_aging_index].aging || (page_frames[i].page_number == 0 && page_frames[min_aging_index].page_number !=0)) min_aging_index = i;

    page_frames[min_aging_index].page_number = current_page;

    for (int i = 0; i < number_of_frames; i++) {
        page_frames[i].aging = page_frames[i].aging >> 1;
        if (i == min_aging_index) page_frames[i].aging = 128;
    }
}

void simulation(int number_of_page_frames){
    FILE *file;
    file = fopen("input.txt", "r");

    int hits = 0, misses = 0;

    Frame page_frames[number_of_page_frames];
    for(int i = 0; i < number_of_page_frames; i++){
        page_frames[i].aging = 0;
        page_frames[i].page_number = 0;
    }

    unsigned int current_page = 0;
    while(!feof(file)) {

        unsigned char is_hit = 0;
        if(fscanf(file, "%ud", &current_page) == 1) {

            int current_index = find_page(current_page, number_of_page_frames, page_frames);

            if (current_index != -1) {
                for (int i = 0; i < number_of_page_frames; i++) {
                    page_frames[i].aging = page_frames[i].aging >> 1;
                    if (i == current_index) page_frames[current_index].aging = page_frames[current_index].aging | 128;
                }
                hits++;
            } else {
                page_replacement(current_page, number_of_page_frames, page_frames);
                misses++;
            }
        }
    }
    printf("Hit/Miss Ratio: %d/%d \n", hits, misses);
}

int main(int argc, char* argv[]){
    //number of page frames
    int n;
    if(argc == 2){
        n = (int)atof(argv[1]);
        simulation(n);
    }
    else printf("Enter as a parameter to a program number of page frames\n");
}



