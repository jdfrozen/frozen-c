#include <stdlib.h>
#include<stdio.h>

struct Book{
 int a;
 char title[6];
};
//堆
struct Book book1={1,"frozen"};
int main(int argc,char *argv[]){
    //栈
    struct Book book={1,"book"};
    printf("book=%p\n",&book);
    printf("book1=%p\n",&book1);
    //堆
    struct Book *book2 = (struct Book *)malloc(sizeof(struct Book));
    printf("book2=%p\n",book2);
    //栈
    struct Book *book3 = (struct Book *)alloca(sizeof(struct Book));
    printf("book3=%p\n",book3);
    return 0;
}
