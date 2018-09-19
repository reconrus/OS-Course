#include <pthread.h>
#include <stdio.h>

void thread(void* a){
  printf("I'm a thread number %d\n", a);
  pthread_exit(NULL);
}

int main() {
  int n = 19;
  pthread_t tid[n];
  pthread_attr_t attr;
  pthread_attr_init(&attr);

  for(int i = 0; i < n; i++){
      pthread_create(&tid[i], &attr, thread, (void*)i);
      printf("Thread %d is created. TID is %d\n", i, tid[i]);
      pthread_join(tid[i], NULL);
  }
}
