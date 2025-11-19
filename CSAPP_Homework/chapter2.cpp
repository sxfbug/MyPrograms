#include<iostream>
#include<bitset>
#include<limits.h>
#include"chapter2headfile.hpp"

using namespace std;

int main(){
    isLittleEnd();
}


//2.58
int isLittleEnd(void){
    int x=0x1;
    int*p=&x;
    printf("%x",p[0]);
    return p[0];
}
