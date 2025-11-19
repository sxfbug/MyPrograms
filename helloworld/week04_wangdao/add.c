#include<stdio.h>
#include<string.h>

//48-57 == 0-9
int main(){
    int i;
    char a[101]={0};
    char b[101]={0};
    int carry=0;
    int all[102]={0};
    
    scanf("%s %s",a,b);
    int pa=strlen(a)-1,pb=strlen(b)-1;
    printf("\npa=%d,pb=%d",pa,pb);
    // for (int i = 0; i < 100; i++)
    // {    
    //     printf("%c",a[i]);
    // }
    
    //前100 位
    for (int i = 101; i >= 0; i--)
    {
        int t1=0,t2=0;
        
        
        t1=pa<0?0:a[pa]-'0';
        t2=pb<0?0:b[pb]-'0';
              
        all[i]=(t1+t2+carry)%10;
        carry=(t1+t2+carry)/10;

        pa--;
        pb--;
        
    }
    //101位
    

    


    for (int i = 0; i < 102; i++)
    {
        printf("i=%d,result=%d\n",i,all[i]);
        /* code */
    }
    

    //print
    int flag=0;
    for (int i = 0; i <102; i++)
    {
        if (all[i]!=0)
        {
            flag=1;
        }
        
        if (all[i]==0&&flag==0)
        {
            continue;
        }else{
            printf("%d",all[i]);
        }
        
        
    }
    
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%c %c ",a[i],b[i]);
    // }
    
}