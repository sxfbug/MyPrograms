#include<stdio.h>
int main(){
    int n,i;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%lf",&x);
        if (x>=0&&x<2)
        {
            printf("y=%.1f",2.5-x);
        }
        if (x>=2&&x<4)
        {
            printf("y=%.1f",2-1.5*(x-3)*(x-3));
        }
        if (x>=4&&x<6)
        {
            printf("y=%.1f",x/2-1.5);
        }
        printf("\n");
    }
    
}