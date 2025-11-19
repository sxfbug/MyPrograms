#include<stdio.h>

int main(){
    int i,j,n=0;
    printf("Hello World! Ms Yang");
    printf("\n");
    for (int i = 9; i >= 1; i=i-2)
    {
        for (int i = 0; i < n; i++)
        {
            printf(" ");
        }
        
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        n++;
        printf("\n");
    }

    for (int i = 3; i <=9; i=i+2)
    {
        for (int i = n-1; i > 1; i--)
        {
            printf(" ");
        }
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        n--;
        printf("\n");
    }
    
}