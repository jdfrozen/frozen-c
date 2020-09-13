#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main(int argc,char *argv[]){
    const char path[12] = "frozen.db";
    int  fd=-1;
    if((fd=creat(&path,0644)) < 0){
        printf("creat failure:\n");
    }
    return 0;
}
