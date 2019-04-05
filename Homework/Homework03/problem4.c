 #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/mman.h>

    int main(){
       int myFile = open("beeMovie.txt", O_RDWR);
       if(myFile < 0){
           printf("open error\n");
       }
       struct stat myStat = {};
       if (fstat(myFile, &myStat)){
           printf("fstat error\n");
       }

       off_t size = myStat.st_size;
       char *addr;
       addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
       if (addr == MAP_FAILED){
           printf("mmap error\n");
       }
       int b = 0;
       while(addr[b] != 'x' || addr[b] != 'X') {
           b++;
       }
       // found
       printf('Very nice! Great success!');
       return 0;
   } 