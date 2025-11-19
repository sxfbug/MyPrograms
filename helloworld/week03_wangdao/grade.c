#include<stdio.h>
#include<malloc.h>
#define SIZE 6
int main(){
    int num,i;
    scanf("%d",&num);
    int* arr=(int*)malloc(sizeof(int)*SIZE);
    //init
    for (int i = 0; i < SIZE ;i++)
    {
        arr[i]=0;
    }
    
    for (int i = 0; i < num; i++)
    {
        int g;
        scanf("%d",&g);
        if (g>=0&&g<60)
        {
            arr[0]++;
        }else if(g>=60&&g<70){
            arr[1]++;
        }else if(g>=70&&g<80){
            arr[2]++;
        }else if(g>=80&&g<90){
            arr[3]++;
        }else if(g>=90&&g<100){
            arr[4]++;
        }else if(g==100){
            arr[5]++;
        }else{

        }
        
    }
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
        /* code */
    }
    
    
}