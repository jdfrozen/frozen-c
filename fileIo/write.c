#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<utime.h>
#include<errno.h>

//打开文件
void openTest(){
    const char path[12] = "frozen.db";
    int  fd=-1;
    //fd=creat(path,0644);
    fd=open(path,O_WRONLY|O_CREAT|O_TRUNC,0644);
    close(fd);
}
//覆盖写文件
void coverTest(){
    char path[12] = "frozen.db";
    int fd=-1;
    fd=open(path,O_WRONLY|O_CREAT,0644);
    //定位SEEK_SET，SEEK_CUR，SEEK_END
    off_t currpos;
    currpos = lseek(fd, 1, SEEK_SET);
    char h[1]="g";
    ssize_t length=write(fd,h,1) ;
    printf("write h %d\n",length);
    close(fd);
}
//指定覆盖写文件
void hollowTest(){
    char path[12] = "frozen.db";
    int fd=-1;
    fd=open(path,O_WRONLY|O_CREAT,0644);
    //定位SEEK_SET，SEEK_CUR，SEEK_END
    off_t currpos;
    currpos = lseek(fd, 20, SEEK_SET);
    char h[1]="g";
    ssize_t length=write(fd,h,1);
    printf("write h %d\n",length);
    close(fd);
}
//追加写文件（原子）
void appandTest(){
    char path[12] = "frozen.db";
    int fd=-1;
    fd=open(path,O_WRONLY|O_CREAT|O_APPEND,0644);
    char h[12]="hhh";
    ssize_t length=write(fd,h,12) ;
    printf("write h %d\n",length);
    close(fd);
}
void utimeTest(){
    char path[12] = "frozen.db";
    struct stat statbuf;
    struct utimbuf timebuf;
    stat(path, &statbuf);
    int fd = open(path, O_RDWR | O_TRUNC);
    close(fd);
    timebuf.actime = statbuf.st_atime;
    timebuf.modtime = statbuf.st_mtime;
    utime(path, &timebuf);
}


int main(int argc,char *argv[]){
    utimeTest();
    return 0;
}
