#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include "unistd.h"
#include <string.h>

//文件的状态信息

int main(int argc,char *argv[]){
    char path[]="frozen.db";
    struct stat sbuf;
    memset(&sbuf, 0, sizeof(sbuf));
    if(stat(path,&sbuf)==-1){
        exit(1);
    }
    printf("st_mode %d",(int)sbuf.st_mode);
    int fd=open(path,O_WRONLY|O_CREAT|O_APPEND,0644);
    struct stat fsbuf;
    memset(&fsbuf, 0, sizeof(fsbuf));
    if(fstat(fd,&fsbuf)==-1){
        exit(1);
    }
    printf("fst_mode %d \n",(int)fsbuf.st_mode);
    if(S_ISREG(fsbuf.st_mode)){
       printf("regular\n");
    }
}
