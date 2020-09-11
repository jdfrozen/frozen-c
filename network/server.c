#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[]){
    const char path[12] = "frozen.db";
    int  fd=-1;
    if((fd=creat(&path,0644)) < 0){
        printf("creat failure:\n");
    }
    return 0;
}
