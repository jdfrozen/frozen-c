#include <stdlib.h>
#include<stdio.h>

int g_val = 0;
int main(int argc,char *argv[]){
    printf("The pid of is: %d\n", getpid());
    printf("The pid of parent is: %d\n", getppid());
    pid_t pid = fork();
    if(pid == 0){
        //子进程
        g_val = 100;
        printf("child val=%d, &val = %d\n", g_val, &g_val);
        sleep(1);
    }
    else{
        wait(NULL);
        printf("parent val=%d, &val = %d\n", g_val, &g_val);
    }

    system("time");
    return 0;
}
