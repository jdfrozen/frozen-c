#include<stdio.h>

int main(int argc,char *argv[]){
    const char path[12] = "frozen.db";
    FILE*  file =fopen(path, "r+b") ;
    fclose(file);
    return 0;
}
