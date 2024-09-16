#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

   if( !fork() ){
      printf("pid 1: %d \n", getpid());
      exit(0);
   }

   if( !fork() ){
      printf("pid 2: %d \n", getpid());
      exit(0);
   }

   if( !fork() ){
      printf("pid 3: %d \n", getpid());
      exit(0);
   }

   printf("FATHER: %d \n", getpid());
   

   return 0;
}