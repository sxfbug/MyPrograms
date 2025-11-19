#include<stdio.h>

int main(){
    int n,m,i;
    int bgg=0;
    while (scanf("%d",&n)!=EOF)
    {
        bgg=0;
        for (int i = 0; i < 10; i++)
        {
            scanf("%d",&m);
            if (bgg==0)
            {
                bgg=n>m?n:m;
            }
            else{
                bgg=bgg>m?bgg:m;
            }
            
        }
        
        printf("max=%d\n",bgg);

        
    }
    
}