#include<stdio.h>
#include<stdlib.h>

void tmpnamTest(){
    char* p;
    p = tmpnam(NULL);
    puts(p);
    printf("%p\n", p);
    puts(tmpnam(NULL));
    printf("%p\n", p);
}
void tmpfileTest(){
    FILE *fp;
    fp = tmpfile();
    printf("临时文件被创建\n");
    fclose(fp);
}

int main(int argc,char *argv[]){
    tmpfileTest();
    return 0;
}
