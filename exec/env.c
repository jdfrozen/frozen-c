#include <stdlib.h>
#include<stdio.h>

extern char **environ;
int main(){
    char **envir = environ;
    while(*envir){
        fprintf(stdout,"%s\n",*envir);
        envir++;
    }
    char *aa= getenv("aa") ;
    fprintf(stdout,"%s\n",aa);
    putenv("aa=bb") ;
    char *aa2= getenv("aa") ;
    fprintf(stdout,"%s\n",aa2);
    return 0;
}
