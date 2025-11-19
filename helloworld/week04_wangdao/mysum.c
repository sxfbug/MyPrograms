#include<stdio.h>
#include<malloc.h>

void  mySum(int *p,  int len,  int *sumOdd,  int *sumEven);
void  mySum(int *p,  int len,  int *sumOdd,  int *sumEven){
    int i;
    *sumOdd=0;
    *sumEven=0;
    for (int i = 0; i < len; i++)
    {   
        //even number
        
        if (p[i]%2==0)
        {
            *sumOdd+=p[i];
        }else{
            *sumEven+=p[i];
        }
        
    }
    
}

int main(){
    int cnt,i;
    int sumOdd=0,sumEven=0;
    scanf("%d",&cnt);
    int* arr=(int*)malloc(sizeof(int)*cnt);
    for (int i = 0; i < cnt; i++)
    {
        /* code */
        scanf("%d",&arr[i]);
        //printf("arr[%d]= %d\n",i,arr[i]);
    }
    mySum(arr,cnt,&sumOdd,&sumEven);
    printf("%d %d",sumEven,sumOdd);
    free(arr);
}