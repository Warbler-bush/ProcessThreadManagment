#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

#include <signal.h>

#define N 50
int main(){

   int pID[2];
   pipe(pID);

   char buf[N];

   if(fork()){
      //father

      int n_read;
      while( (n_read =read(pID[0],buf,N))>0){
         printf("%s",buf);
      }
      printf("END PRINTINF FATHER \n");
      exit(0);
   }else{
      // son
      int fid =open("secrect_text_4.txt",O_RDONLY, S_IRWXU);
      int n_read1;

      while( (n_read1 = read(fid, buf,N) ) > 0){
         write(pID[1],buf,n_read1);
      }
      close(fid);
      close(pID[1]);
      close(pID[0]);
      exit(0);
   }


}