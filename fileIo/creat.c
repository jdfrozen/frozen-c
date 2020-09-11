#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

int main(int argc,char *argv[]){
    const char path[12] = "frozen.db";
    int  fd=-1;
    //fd=creat(path,0644);
    fd=open(path,O_WRONLY|O_CREAT|O_TRUNC,0644);

    return 0;
}
