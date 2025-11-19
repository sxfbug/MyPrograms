#include<stdio.h>
#include<malloc.h>
#define SIZE 10
int main(){
    int i,n;
    int* arr=(int*)malloc(sizeof(int)*SIZE);
    for (int i = 0; i < SIZE-1; i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&n);
    int cnt;
    for (int i = 0; i < SIZE-1; i++)
    {
        if (arr[i]>n)
        {
            cnt=i;
            break;
        }
        
    }
    for (int i = SIZE-2; i >= cnt; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[cnt]=n;

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n",arr[i]);
        /* code */
    }
    
    
    
}