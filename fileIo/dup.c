#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

//复制文件描述符

//复制文件描述符
void dupTest(){
    char path[12] = "frozen.db";
    int fd=open(path,O_WRONLY|O_CREAT|O_APPEND,0644);
    int fd1=dup(fd);
    char h[12]="hhh";
    ssize_t length=write(fd1,h,12) ;
    printf("write h %d\n",length);
    close(fd);
}

//重定向，将文件输出>标准输出
void dup2Test(){
    char path[12] = "frozen.db";
    int fd=open(path,O_WRONLY|O_CREAT|O_APPEND,0644);
    //获取标准输出的文件描述符
    int sfd=fileno(stdout);
    int fd1=dup2(sfd,fd);
    char h[12]="hhh";
    ssize_t length=write(fd,h,12) ;
    close(fd);
}

int main(int argc,char *argv[]){
    dup2Test();
}
