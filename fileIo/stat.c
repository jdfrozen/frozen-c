#include<sys/types.h>
#include<sys/stat.h>
#include <unistd.h>
int main(int argc,char *argv[]){
    char path[]="frozen.db";
    struct stat sbuf;
    if(stat(path,&sbuf)==-1){
        ERR_EXIT("stat error");
    }
    printf("%s",sbuf.st_mode);
}
