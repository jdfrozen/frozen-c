#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

//打开文件
void mkdirTest(){
    const char path[12] = "frozen.db";
    int result=mkdir(path,0644);
    if(result!=-1){
        printf("mkdir success");
    }else{
        printf("mkdir error");
    }
}
//打开文件
void rmdirTest(){
    const char path[12] = "frozen.db";
    int result=rmdir(path);
    if(result!=-1){
        printf("rmdir success");
    }else{
        printf("rmdir error");
    }
}


int main(int argc,char *argv[]){
    mkdirTest();
    rmdirTest();
    return 0;
}
