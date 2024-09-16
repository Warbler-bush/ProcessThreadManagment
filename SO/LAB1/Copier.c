#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[] ){
   FILE* fp = fopen(argv[1], "r");
   FILE* fp2 = fopen(argv[2],"w");
   int c ;
   
   while(  (c = fgetc(fp) ) != EOF)
      fputc(c,fp2);


   fclose(fp);
   fclose(fp2);
   return 0;
}