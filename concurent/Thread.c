#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void run(){
    printf("this is a pthread. \n");
    sleep(30);
}
//gcc Thread.c -lpthread
int main(int argc ,char *argv[]){
    pthread_t id;
    int i,ret;
    ret=pthread_create(&id,NULL,(void *)run,NULL);
    if(ret!=0){
        printf("Create pthread error!\n");
        exit(1);
    }
    printf("this is the main process. \n");
    pthread_join(id,NULL);
    return 0;
}

//比较两个线程是否相等
