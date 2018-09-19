#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define TRUE 1
#define FALSE 0

int counter;
int buffer[BUFFER_SIZE];

int consumer_awake;
int producer_awake;

void sleep(int* awake){
  *awake = FALSE;
}

void wakeup(int* awake){
  *awake = TRUE;
}

void produce(int* a){
  srand(time(NULL));

  while(TRUE){
    while(producer_awake){
      if(counter >= BUFFER_SIZE)
        sleep(&producer_awake);
      else{
        int new_item = rand();
        buffer[counter] = new_item;
        counter++;
      }
      if(counter > 0)
        wakeup(&consumer_awake);
    }
  }
}

void consume(){
  while(TRUE){
      while(consumer_awake){
        if(counter <= 0){
          sleep(&consumer_awake);
        }
        else{
          counter--;
        }
        if(counter < BUFFER_SIZE)
          wakeup(&producer_awake);
      }
  }
}

void print(){
  while(TRUE){
    if(counter > 0)
      printf("Last produced number: %d\n", buffer[counter-1]);
    else
      printf("Buffer is empty\n");
  }
}


int main(){
    counter = 0;

    pthread_t producerID;
    pthread_t consumerID;
    pthread_t printerID;

    producer_awake = TRUE;
    consumer_awake = FALSE;

    pthread_create(&producerID, NULL, produce, NULL);
    pthread_create(&consumerID, NULL, consume, NULL);
    pthread_create(&printerID, NULL, print, NULL);

    pthread_join(producerID, NULL);
    pthread_join(consumerID, NULL);
    pthread_join(printerID, NULL);

    return 0;
}
