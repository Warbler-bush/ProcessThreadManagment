#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int A, B;

void sum(){
   printf("Invocato la USR1: sum %d\n",A+B);
}

void sub(){
   printf("Invocato la USR2: sub %d\n",A-B);
}

int main(int argc, char* argv[]){
   A = atoi(argv[1]);
   B = atoi(argv[2]);

   signal(SIGUSR1,sum );
   signal(SIGUSR2,sub);
   signal(SIGINT,SIG_DFL);

   int i;
   
   while(1){
      printf("Inserire il segnale da mandare (1 = SIGUSR1 , 2 = SIGUSR2 3 = SIGINT): ");
      scanf("%d",&i);
      printf("\n");

      if(i == 1) kill(getpid(), SIGUSR1 );
      else if(i == 2) kill(getpid(),SIGUSR2);
      else if(i == 3) kill(getpid(),SIGINT);
      else printf("GIT GOOD AT READING! (1 2 3) OK?\n");
   }

   return 0;
}