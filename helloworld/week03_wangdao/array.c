#include<stdio.h>
#include<malloc.h>
int main(){
    int s,i,j=0,times;
    scanf("%d",&s);
    int* arr=(int*)malloc(sizeof(int)*s);
    int len=s;
    for (int i = 0; i < s; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&times);
    //取mod减少移动次数
    times=times%s;
    for (int i = 0; i < times; i++)
    {
        int temp=arr[len-1];

        for (int j = len-1; j > 0; j--)
        {
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
        
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
    

}