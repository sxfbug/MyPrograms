#include<stdio.h>
int even(int n);
int even(int n){
    if (n%2==0)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int main(){
    int n,sum=0;
    scanf("%d",&n);
    while (n>0)
    {
        if (!even(n))
        {
            sum+=n;
        }

        scanf("%d",&n);
        
    }
    printf("%d",sum);
    
}