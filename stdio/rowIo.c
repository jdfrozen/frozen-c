#include<stdio.h>
#include<stdlib.h>
//行输入输出

//行标准输出
void lwio(){
    const char path[12] = "frozen.db";
    FILE* file =fopen(path, "r+b");
    fputs("frozen", file);
    fclose(file);
}
//行标准输入
void lrio(){
    const char path[12] = "frozen.db";
    char* buf = (char*)malloc(100 * sizeof(char));
    FILE*  file =fopen(path, "r+b");
    char* frozen = fgets(buf,30,file);
    printf("c=%s\n",frozen);
    fclose(file);
}

int main(int argc,char *argv[]){
    lwio();
    lrio();
    return 0;
}
