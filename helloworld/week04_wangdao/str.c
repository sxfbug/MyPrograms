#include<stdio.h>

void pri(char x[]);
void pri(char x[]){
    int i;
    for (int i = 0; i < 100; i++)
    {
        if (x[i]!=0)
        {
           printf("%c",x[i]);
        }else{
            break;
        }
        
    }
    printf("\n");
    
}
int main(){
    char a[100]={0};
    char b[100]={0};
    char c[100]={0};
    int i=0;
    
    scanf("%s %s %s",a,b,c);
          
    if (a[i]<b[i]&&a[i]<c[i])
    {
        pri(a);
        if(b[i]<c[i]){
        pri(b);
        pri(c);
        //break;
    }else if(b[i]>=c[i]){
        pri(c);
        pri(b);
        //break;
    }
    }

    if (b[i]<a[i]&&b[i]<c[i])
    {
        pri(b);
        if(a[i]<c[i]){
        pri(a);
        pri(c);
        //break;
    }else if(a[i]>=c[i]){
        pri(c);
        pri(a);
        //break;
    }
    }
    

    if (c[i]<b[i]&&c[i]<a[i])
    {
        pri(c);
        if(b[i]<a[i]){
        pri(b);
        pri(a);
        //break;
    }else if(b[i]>=a[i]){
        pri(a);
        pri(b);
        //break;
    }
    }
        
        
    
    
}