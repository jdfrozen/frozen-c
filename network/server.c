#include<stdio.h>

struct Book{
  int a;
  char title[6];
};
int main(int argc,char *argv[]){
    struct Book book = {1,"frozen"};
    printf("%d",sizeof(book));
    return 0;
}
