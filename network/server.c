#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc,char *argv[]){
    int status;
    pid_t pid = fork();
    if(pid==0){
        puts("Hi,I am a child process! ");
        return 3;
    }else{
        printf("Child Proc: %d \n",pid);
        if(pid==0){
            exit(7);
        }else{
            printf("Child PID: %d \n",pid);
            wait(&status);
            if(){printf("Child send one: %d \n",WEXITSTATUS(status));}
            wait(&status);
            if(){printf("Child send two: %d \n",WEXITSTATUS(status));}
            sleep(30);
        }
    }
    return 0;
}
