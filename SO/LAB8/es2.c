#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define DIM 50

void* checkup(void * pargv){
   
   char* stringa;   
   while(1){
      sleep(1);   
      stringa = pargv;
      if(strcmp("house",stringa) == 0 || strcmp("casa",stringa) == 0 ){
         printf("\n[THREAD] CASA RILEVATA: %s\n",stringa);
         strcpy(stringa , "MIAO");
      }
      
   }
}

int main(){
   char stringa[DIM];

   pthread_t pt1;

   void* pargv;
   pargv = stringa;
   pthread_create(&pt1,NULL,&checkup,pargv);

   do{
      printf("inserire la parola:");
      scanf("%s",stringa);
   }while( strcmp(stringa,"exit") );

   exit(0);
}