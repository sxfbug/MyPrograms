#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int num,all;
        scanf("%d %d",&num,&all);
        int a,b,c,cnt;
        cnt=0;
        for (int c = 0; c <= num; c++)
        {
            for (int b = 0; b <= num-c; b++)
            {
                a=num-c-b;
                if(a+2*b+5*c==all){
                    cnt++;
                }
                
            }
            
        }
        printf("%d\n",cnt);
    }
    
}