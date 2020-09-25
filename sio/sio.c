#include<stdio.h>

void sio(){
    const char path[12] = "frozen.db";
    FILE*  file =fopen(path, "r+b");
    //设置缓存
    char buf[1024];
    setbuf(file, buf);
    fclose(file);
}
int main(int argc,char *argv[]){
    sio();
    return 0;
}
