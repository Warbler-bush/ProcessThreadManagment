#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main(){

   printf("FATHER GOD\n");
   if( !fork() ){
      printf("SON 1 :%d\n",getpid());
      if(!fork() ){
         printf("GRANDSON 1 :%d\n",getpid());
         if(!fork() )
         {
            printf("GRAND-GRANDSON 1 :%d\n",getpid());
         }
      }
   }

   return 0;
}