#include<stdio.h>
int Gcd(int a,int b);
int Gcd(int a,int b){
    if (a>b)
    {
        return Gcd(a-b,b);
    }else if(a<b){
        return Gcd(a,b-a);
    }else{
        return a;
    }
    
}
int main(){
    int m,n,re;
    scanf("%d,%d",&m,&n);
    re=Gcd(m,n);
    printf("%d",re);
}