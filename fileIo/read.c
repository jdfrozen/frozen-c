#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[]){
    char path[12] = "frozen.db";
    int fd=-1;
    fd=open(path,O_RDWR|O_CREAT,0644);
    //定位SEEK_SET，SEEK_CUR，SEEK_END
    off_t currpos = lseek(fd, 1, SEEK_SET);
    char h[10];
    ssize_t length=read(fd,h,10);
    printf("read length %d\n",length);
    printf("read h %s\n",h);
    return 0;
}
