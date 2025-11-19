#include<iostream>

int main(){
    int arr[4]={1,2,3,-1};
    int a,b;
    scanf("%d %d",&a,&b);
    for (int i = 3; i >= 2; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[1]=a;

    for (int i = 0; i < 4; i++)
    {
        printf("  %d",arr[i]);
    }
    printf("\n");

    if (b>4)
    {
        printf("false");
        return 0;
    }
    
    if (b==4)
    {
        arr[3]==-1;
        for (int i = 0; i < 3; i++)
        {
            printf("  %d",arr[i]);
        }
           
    }
    
    for (int i = b-1; i < 3; i++)
    {
        arr[i]=arr[i+1];
    }
    for (int i = 0; i < 3; i++)
        {
            printf("  %d",arr[i]);
        }


}