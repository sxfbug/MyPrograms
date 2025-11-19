#include<stdio.h>
#include<malloc.h>
#define SIZE 10
void search(int *pa,int n,int *pmax,int *pflag);
void search(int *pa,int n,int *pmax,int *pflag){
    *pmax=0;
    *pflag=0;
    int i;
    for (int i = 0; i < n; i++)
    {
        if (*pmax<pa[i])
        {
            *pmax=pa[i];
            *pflag=i;
        }
        
    }
    
}

int main(){
    int i;
    int arr[SIZE]={0};
    int pmax,pflag;
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d",&arr[i]);
    }
    search(arr,SIZE,&pmax,&pflag);
    printf("Max is:%d\nMax position is:%d",pmax,pflag);
}