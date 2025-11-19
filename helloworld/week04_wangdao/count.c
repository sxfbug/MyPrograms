//num:48-57
//word:65-90 97-122
//space:32

#include<stdio.h>

int main(){
    char s[100]={0};
    char x='0';
    int i=0,word=0,num=0,space=0;
    for (int i = 0; i < 100; i++)
    {
        if(scanf("%c",&x)!=EOF){
            s[i]=x;
        }
        
    }
    
    

    while (s[i]!=0)
    {
        if (s[i]>=48&&s[i]<=57)
        {
            num++;
        }else if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)){
            word++;
        }else if(s[i]==32){
            space++;
        }
        i++;
        
    }
    printf("%d %d %d",word,num,space);
}