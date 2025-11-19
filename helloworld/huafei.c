#include<stdio.h>
int main(){
    int k,m;
    scanf("%d %d",&m,&k);
    while (k!=0&&m!=0)
    {
        int days=0;
        while (m>=k)
        {
            days+=m;
            m=m/k;
        }
        days+=m;
        printf("%d\n",days);
        scanf("%d %d",&m,&k);
        if(m==0&&k==0){
            break;
        }

    }
    
}