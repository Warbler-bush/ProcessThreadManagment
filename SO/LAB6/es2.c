
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
   int N = atoi( argv[1])-1;

   int** pIDs;
   pIDs = (int**) malloc(sizeof(int*)*N);

   
   printf("OK\n");
   
   int i=0;
   for(i = 0; i< N ; i++){
      pIDs[i] = (int*)malloc(sizeof(int)* 2 );
      if(  (pipe(pIDs[i]) ) ){ 
         printf("ERROR CREATING PIPE !!! EXITING RN");
         exit(0);
      }
   }

   printf("OK\n");
   
   for( i = 0 ; i < N ; i++){
      if( !fork() ){
         //figlio
         double res;
         res = exp(i+1) / (i+1);
         write(pIDs[i][1],&res,sizeof(double));
         close(pIDs[i][1]);
         exit(0);
      }
   }
   
   sleep(1);

   double sum = 0;
   double num = 0;
   for(i = 0; i< N ; i++){
      read(pIDs[i][0],&num,sizeof(double));
      sum += num;
      close(pIDs[i][0]);
      free(pIDs[i]);
   }
   free(pIDs);
   printf("final sum :%f\n",sum);
   
   return 0;
}