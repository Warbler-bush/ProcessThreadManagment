#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 200

void childhandler(){
   printf("[FATHER]: ONE CHILD HAS COMPLETED HIS HOLY MISSION\n");
}

void nothinghandler(){
   printf("[CHILD1]: ROGERRRRRR, BROTHER2! GO AHEAD AND WORK SLAVES!\n");
}

int main(){

   int pchild1 ;
   int pchild2 ;

   char buf[BUF_SIZE];
   
   //figlio 1
   if(!  (pchild1= fork() ) ){
      signal(SIGUSR1,nothinghandler);
      pause();
      
      int fd1 = open("son1.txt",O_RDONLY,S_IRWXU);
      int n_read;
      while( (n_read = read(fd1,buf,BUF_SIZE) ) > 0 )
         printf("%s",buf);
      close(fd1);

      /* test case
      printf(" [%d - CHILD1]:CODING...\n",getpid());
      sleep(1);
      printf("[%d- CHILD1]:END\n",getpid());
      */
      
      
      
      exit(0);
   }

   //figlio 2
   if(!  (pchild2= fork() ) ){
      
      int fd1 = open("son2.txt",O_RDONLY,S_IRWXU);
      int n_read;
      while( (n_read = read(fd1,buf,BUF_SIZE) ) > 0 )
         printf("%s",buf);
      close(fd1);
      

      /*      
       printf("[%d]:CODING...\n",getpid());
         sleep(1);
         printf("[%d]:END\n",getpid());
      */


      sleep(5);
      kill(pchild1,SIGUSR1);
      exit(0);
   }
   printf("[FATHER]: CHILDs ARE %d %d \n",pchild1,pchild2);

   signal(SIGCHLD,childhandler);
   pause();
   pause();
   printf("[FATHER]: WORK DONE! FOR THE GOD! (booom)....\n");
   return 0;
}