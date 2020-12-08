#include <stdio.h>
#include <unistd.h>

int gval=11;
int main(int argc,char *argv[]){
    pid_t pid;
    int lval=25;
    pid = fork();
    if(pid==0){
        gval++;
        lval++;
        printf("Parent Proc: %d %d \n",gval,lval);
    }else{
        gval++;
        lval++;
        printf("Child Proc: %d %d \n",gval,lval);
    }
    return 0;
}
