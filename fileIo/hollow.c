#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[]){
    char path[12] = "frozen.db";
    int fd=-1;
    fd=open(path,O_WRONLY|O_CREAT,0644);
    //定位SEEK_SET，SEEK_CUR，SEEK_END
    off_t currpos;
    currpos = lseek(fd, 20, SEEK_SET);
    char h[1]="g";
    ssize_t length=write(fd,h,1);
    printf("write h %d\n",length);
    return 0;
}