#include<stdio.h>

//单个字符的输入输出

//字符标准输出
void cwio(){
    const char path[12] = "frozen.db";
    FILE*  file =fopen(path, "r+b");
    int c =fputc(5, file);
    printf("c=%d\n",c);
    fclose(file);
}
//字符标准输入
void crio(){
    const char path[12] = "frozen.db";
    FILE*  file =fopen(path, "r+b");
    int c =fgetc(file);
    printf("c=%d\n",c);
    fclose(file);
}

int main(int argc,char *argv[]){
    cwio();
    crio();
    return 0;
}
