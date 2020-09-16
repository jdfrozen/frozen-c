#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[]){
    char path[]="frozen.db";
    struct stat sbuf;
    memset(&sbuf, 0, sizeof(sbuf));
    if(stat(path,&sbuf)==-1){
        exit(1);
    }
    printf("st_mode %d",(int)sbuf.st_mode);
}
