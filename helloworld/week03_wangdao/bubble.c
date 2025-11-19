#include<stdio.h>
#include<malloc.h>
int main(){
    int num,i,j;
    int temp;
    scanf("%d",&num);
    int* arr=(int*)malloc(sizeof(int)*num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    for(int j=0;j<num-i;j++){
        for (int i = 0; i < num-1; i++)
    {
        if (arr[i]>arr[i+1])
        {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        
    }
    }
    
    for (int i = 0; i < num; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    
}