#include<stdio.h>

int main(){
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int sum=0,now=0;
        while (n>1)
        {
            now=n%10;
            if (now%2==0)
            {
                sum+=now;
            }
            
            n/=10;
        }
        printf("%d\n",sum);

        
    }
    
}