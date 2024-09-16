#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
   int i = 0 ;
   int j = 0 ;
   int val = 0;

   
   int val2 = 0;
   for(i = 0; i< 3; i++){
      // tipologia 1 random num gen
      if(!fork()){
         // sleep per evitare che il figlo finisha prima 
         //che il padre vada in wait
         sleep(3);
         srand(getpid());
         val2 = rand()%100;
         printf("rand:%d\n",val2  ) ;
         exit(1);
      }
   }

   for(i = 0 ; i< 3 ; i++){
      // tipologia 2 random 50 e radice
      if(!fork()){
         sleep(1);
         srand(getpid());
         for(j = 0; j< 50; j++){
            val = rand()%100;
            printf("rand2:%d sqrt: %d \n",val, val* val );
         }
         exit(2);
      }
   }
   
   int status;
   while(1){
      wait(&status);
      status = WEXITSTATUS(status);
      printf("WAITED CHILD WITH STATUS %d\n",status);
      if(status == 1 ){
         if(!fork()){
            // sleep per evitare che il figlo finisha prima 
            //che il padre vada in wait
            sleep(1);
            srand(getpid());
            printf("rand:%d\n", rand()%100 ) ;
            exit(1);
         }
      }

      if(status == 2){
         if(!fork()){
            srand(getpid());
            sleep(1);
            for(j = 0; j< 50; j++){
               val = rand()%100;
               printf("rand2:%d sqrt: %d \n",val, val* val );
            }
            exit(2);
         }
      }
   }

   return 0;
}