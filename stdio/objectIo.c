#include<stdio.h>
#include<stdlib.h>

//对象的输入输出

struct Book{
 int a;
 char title[6];
};
void owio(){
    const char path[12] = "frozen.db";
    FILE* file =fopen(path, "r+b");
    struct Book book = {1,"frozen"};
    if (fwrite(&book, sizeof(book), 1, file) != 1){
        printf("fwrite error\n");
    }
    fclose(file);
}
void orio(){
    const char path[12] = "frozen.db";
    FILE*  file =fopen(path, "r+b");
    struct Book book = {2,"frozen"};
    struct Book book1[12];
    fread(book1, sizeof(book), 1, file);
    printf("c=%d\n",book1[0].a);
    fclose(file);
}

int main(int argc,char *argv[]){
    owio();
    orio();
    return 0;
}
