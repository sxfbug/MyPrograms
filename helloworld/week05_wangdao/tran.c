#include<stdio.h>

//除基数取余数，最先取的余数是最低位的数值

void fuc(int a,int n);
void fuc(int a,int n){
    if (a/n==0)
    {
        printf("%d",a);
        return ;
    }else{
        fuc(a/n,n);
    }
    printf("%d",a%n);
    
}

int main(){
    int a;
    while (scanf("%d",&a)!=EOF)
    {
        fuc(a,8);
        printf("\n");
    }
    
    
}