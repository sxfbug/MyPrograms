#include<stdio.h>
#define f "First"
#define s "Second"
#define m "Same"
int main(){
    int n,i;
    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        int m1,m2,s1,s2,r1,r2;
        int a,b;
        int t1,t2;
        t1=scanf("%d %d %d",&m1,&s1,&r1);
        t2=scanf("%d%d %d",&m2,&s2,&r2);
        {
            printf("t1: %d\t",t1);
            printf("t2: %d\n",t2);
        }
        a=m1*100+s1*10+r1;
        b=m2*100+s2*10+r2;
        if (a>b)
        {
            printf("%s",f);
        }else if(a<b){
            printf("%s",s);
        }else{
            printf("%s",m);
        }
        printf("\n");

        
        
    }
    
}