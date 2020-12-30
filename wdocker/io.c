#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<utime.h>
#include<errno.h>
#include <sys/syscall.h>

void appandTest(){
    printf("[%d] -[%d]- start \n", getpid(),syscall(SYS_gettid));
    char h[1024];
    char sda1_path[20] = "/dev/sda1";
    int sda1_fd=-1;
    sda1_fd=open(sda1_path,O_RDWR|O_CREAT,0644);
    off_t currpos = lseek(sda1_fd, 0, SEEK_SET);
    char null_path[20] = "/home/frozen/file1";
    int null_fd=-1;
    null_fd=open(null_path,O_WRONLY|O_CREAT|O_APPEND,0644);
    for(;;){
        ssize_t read_l=read(sda1_fd,h,1024);
        //printf("read length %d\n",read_l);
        if(read_l<=0){
            break;
        }
        ssize_t write_l=write(null_fd,h,read_l) ;
    }
    close(sda1_fd);
    close(null_fd);
}

int main(int argc,char *argv[]){
    for(int i=0;i<5;i++){
        appandTest();
    }
    return 0;
}
