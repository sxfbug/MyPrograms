#include<stdio.h>
#define w1 150
#define w2 200
#define w3 350
int main(){
    int n,i;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        //m>=350
        if (m%w2==0||m%w1==0)
        {
            m=0;
        }
        
        while (m>=w3)
        {
            m-=w3;
        }
        //200<=m<350
        if (m>=w2)
        {
           m-=w2;
        }
        //150<=m<200
        else if(m>=w1){
            m-=w1;
        }
        printf("%d\n",m);
    }


}