#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
   
   printf("A\n");
   
   int pid = fork();
   
   printf("B\n");
   
   if (pid)
   {
      printf("Father waiting\n");
      wait(NULL);
   }else{
   
      printf("C\n");
      sleep(5);
      exit(0);
   }
   return 0;
}