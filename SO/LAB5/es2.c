#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>


int main(int argc, char* argv[]){
   int pid = atoi(argv[1]);
   printf("[%d]: ricevuto il pid %d\n",getpid(),pid);
 
  int i;
   while(1){
      printf("[%d] Inserire il segnale da mandare (1 = SIGUSR1 , 2 = SIGUSR2 3 = SIGINT 4 = exit): ",getpid());
      scanf("%d",&i);
      printf("\n");

      if(i == 1) kill(pid, SIGUSR1 );
      else if(i == 2) kill(pid,SIGUSR2);
      else if(i == 3) kill(pid,SIGINT);
      else if (i == 4) exit(0);
      else printf("GIT GOOD AT READING! (1 2 3 4) OK?\n");
   }

}