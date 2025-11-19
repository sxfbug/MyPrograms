#include<stdio.h>
#include<iostream>
#include<bitset>

using namespace std;

int t1(int x,int y){
    return ~(x&y) & ~(~x&~y);
}
int main(){
    int x=-2147483648,y=-2147483648;
    cout<<bitset<32>(x);
        cout<<endl;
    cout<<bitset<32>(y);
    cout<<endl;
    printf("%d",t1(x,y));
}