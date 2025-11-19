#include<stdio.h>

void candy(int x,int *cnt);
void candy(int x,int *cnt){
    if (x==1||x==0)
    {
        (*cnt)++;
        return;
    }else if(x>1){
        candy(x-1,cnt);
        candy(x-2,cnt);
        
    }
    return;
}
int main(){
    int x,cnt;
    while (scanf("%d",&x)!=EOF)
    {
        cnt=0;
        candy(x,&cnt);
        printf("%d\n",cnt);
    }
    
    
}