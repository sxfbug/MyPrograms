#include<iostream>
#include<cstdlib>
#include<cstring>
#include<malloc.h>

struct tt
{
    int data;
    int* te;
};


int main(){
    tt x;
    x.data=1;
    x.te=(int*)malloc(sizeof(int*));
    int a=5;
    int b=3;
    *x.te=a;
    printf("%d\n",*x.te);
    printf("%p",x.te);

    //cout<<"try to shallow copy\n";

    tt y;
    y.te=(int*)malloc(sizeof(int));
    y.te=&a;
    // y.data=x.data;
    // y.te=x.te;
    // free(x.te);

    // size_t size = malloc_usable_size(x.te);
    // memset(x.te, 0xCC, size);

    //能读取到一个垃圾value,但是不会引发程序崩溃
    printf("\n%d",*y.te);
    //free(y.te);
}