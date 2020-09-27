#include <stdlib.h>
#include<stdio.h>

void func1(){
    printf("this function is func1\n");
}
void func2(){
    printf("this function is func2\n");
}
int main(int argc,char *argv[]){
    atexit(func1);
    atexit(func2);
    exit(0);
    return 0;
}
