#include<stdio.h>

typedef struct test_type
{
    int d1;
    double d2;
    char d3;
    
}tt;

int main(){
    tt a={1,2.0,'s'};
    printf("size of struct: %lu\n",sizeof(tt));
    printf("size of a: %lu\n",sizeof(a));
    printf("size of all element: %lu\n",sizeof(int)+sizeof(double)+sizeof(char));

}