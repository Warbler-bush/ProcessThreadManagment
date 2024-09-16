#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>


void* thread_primo(void* args){
   printf("Elaborazione del primo thread\n");
   sleep(4);
   printf("Fine elaborazione del primo thread\n");
   pthread_exit(NULL);
}

void* thread_secondo(void *args){
   printf("Elaborazione del secondo thread\n");
   sleep(5);
   printf("Fine elaborazione del secondo thread\n");
   pthread_exit(NULL);
}

int main(){
   pthread_t p1;
   pthread_t p2;

   printf("Primo Thread Creato\n");
   pthread_create(&p1,NULL,&thread_primo,NULL);
   printf("Secondo Thread Creato\n");
   pthread_create(&p2,NULL,&thread_secondo,NULL);



   pthread_exit(NULL);
}