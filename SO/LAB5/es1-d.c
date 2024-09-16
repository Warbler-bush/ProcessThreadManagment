#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int A, B;

void sum(){
   sleep(1);
   printf("[%d]: Invocato la USR1: sum %d\n",getpid(),A+B);
}

void sub(){
   sleep(1);
   printf("[%d] Invocato la USR2: sub %d\n",getpid(),A-B);
}

void inter(){
   sleep(1);
   printf("[%d] : Invocato lo SIGINT exiting..\n",getpid());
   exit(0);
}

int main(int argc, char* argv[]){
   A = atoi(argv[1]);
   B = atoi(argv[2]);

   signal(SIGUSR1,sum );
   signal(SIGUSR2,sub);
   //signal(SIGINT,SIG_DFL);
   signal(SIGINT, inter);

   printf("pid:%d\n",getpid());
   
   int i;   
   while(1){}

   return 0;
}