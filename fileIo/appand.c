#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[]){
    char path[12] = "frozen.db";
    int fd=-1;
    fd=open(path,O_WRONLY|O_CREAT|O_APPEND,0644);
    char h[12]="hhh";
    ssize_t length=write(fd,h,12) ;
    printf("write h %d\n",length);
    return 0;
}
