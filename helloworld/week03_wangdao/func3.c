#include<stdio.h>
int rev(int num);


int rev(int num){
    int temp;
    int final=0;
    while (num>0)
    {
        /* code */
        final*=10;
        temp=num%10;
        num/=10;
        final+=temp;
        
    }
    
    return final;
}


int main(){
    int n,i;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d ",rev(x));
    }
    
}