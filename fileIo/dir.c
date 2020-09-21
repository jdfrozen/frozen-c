#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include <dirent.h>

//创建目录
void mkdirTest(){
    const char path[12] = "frozen";
    int result=mkdir(path,0644);
    if(result!=-1){
        printf("mkdir success");
    }else{
        printf("mkdir error");
    }
}
//删除目录
void rmdirTest(){
    const char path[12] = "frozen";
    int result=rmdir(path);
    if(result!=-1){
        printf("rmdir success");
    }else{
        printf("rmdir error");
    }
}

//读取目录文件名列表
void readdirTest(){
    const char path[12] = "frozen";
    DIR *dir_ptr;
    struct dirent *direntp;
    dir_ptr = opendir(path);
    if(dir_ptr == NULL){
        printf("dir_ptr null\n");
    }
    while((direntp = readdir(dir_ptr)) != NULL)
    {
        printf("d_name : %s\n", direntp->d_name);
    }
    closedir(dir_ptr);
}
//当前目录
void pwdTest(){
     char save_cwd[1024];
     char buf[1024];
     getcwd(save_cwd, sizeof(save_cwd));
     printf("before chdir, cwd = %s\n", save_cwd);
     chdir("/opt/c/fileIo/frozen1");
     getcwd(buf, sizeof(buf));
     printf("after chdir, cwd = %s\n", buf);
     const char path[1024] = "/opt/c/fileIo/frozen";
     int fd=open(path, O_RDONLY);
     fchdir(fd);
     getcwd(buf, sizeof(buf));
     printf("after fchdir, cwd = %s\n", buf);
     close(fd);
}


int main(int argc,char *argv[]){
    pwdTest();
    return 0;
}
