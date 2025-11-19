#include<stdio.h>

//和原本的n条线相交，形成n+1个新的面

int line(int x);
int line(int x){
    if (x==1)
    {
        return 2;
    }else{
        return line(x-1)+x;
    }
    
}
int main(){
    int x;
    while (scanf("%d",&x)!=EOF)
    {
        /* code */
        printf("%d\n",line(x));
    }
    
    
}
