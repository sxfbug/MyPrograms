#include<stdio.h>

void cards(int x,int *c);
void cards(int x,int *c){
    if (x>=3)
    {
        cards(x-3,c);
        cards(x-2,c);
        cards(x-1,c);
    }else if(x>=2){
        cards(x-2,c);
        cards(x-1,c);
    }else if(x>=1){
        cards(x-1,c);
    }else{
        (*c)++;
        return;
    }
    
}
int main(){
    int x,c=0;
    scanf("%d",&x);
    cards(x,&c);
    printf("%d",c);
}