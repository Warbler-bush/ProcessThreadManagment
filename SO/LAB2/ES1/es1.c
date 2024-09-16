#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define DIM 500


int main(int argc, char* argv[]){
   int fdr = open(argv[1], O_RDONLY , S_IRWXU);
   int fdw = open(argv[2],O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
   int buf[DIM];

   int bytes_read;
   while(  (bytes_read = read(fdr,buf, DIM)) > 0 ){
      write(fdw,buf,bytes_read);
   }


   close(fdw);
   close(fdr);
   return 0;
}