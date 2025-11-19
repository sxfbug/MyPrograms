/*
Description

计算两个矩阵的乘积，第一个是2*3矩阵，第二个是3*2矩阵，结果为一个2*2矩阵。


Input

输入包含多组数据，先输入一个2*3矩阵，再输入一个3*2矩阵。


Output

输出两个矩阵的乘积。
*/
#include<stdio.h>
#include<malloc.h>
#define COLOUMS 3
#define ROW 2
int main(){
    int* arr1=(int*)malloc(sizeof(int)*COLOUMS*ROW);
    int* arr2=(int*)malloc(sizeof(int)*COLOUMS*ROW);
    int* arr3=(int*)malloc(sizeof(int)*ROW*ROW);

    while (scanf("%d",arr1)!=EOF)
    {   
        int i,j,m,n;
        //init arr1
        
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLOUMS; j++)
            {   
                if (i==0&&j==0)
                {
                    continue;
                }
                
                int* p1=arr1+i*COLOUMS+j;
                scanf("%d",p1);
                
            }
            
            
        }

        //init arr2 3*2
        for (int i = 0; i < COLOUMS; i++)
        {
            for (int j = 0; j < ROW; j++)
            {
                int* p2=arr2+i*ROW+j;
                scanf("%d",p2);
                
            }
            
            
        }
        

        //check arr1 and arr2
        // printf("\ncheck:\n");
        // for (int i = 0; i < ROW; i++)
        // {
        //     for (int j = 0; j < COLOUMS; j++)
        //     {
        //         printf("%d ",*(arr1+i*COLOUMS+j));
        //     }
        //     printf("\n");
        // }

        // for (int i = 0; i < COLOUMS; i++)
        // {
        //     for (int j = 0; j < ROW; j++)
        //     {
        //         printf("%d ",*(arr2+i*ROW+j));
        //     }
        //     printf("\n");
        // }
        
        
        //count
        
        for (int m = 0; m< ROW; m++)
        {
            for (int n = 0; n < ROW; n++)
            {
                int a=0;
                for (int i = 0; i < COLOUMS; i++)
                {
                    //arr1 m行 和 arr2 n列
                    // if (i==2&&m==1)
                    // {
                    //     printf("i=2,m=1,val=%d",*(arr1+m*COLOUMS*i));
                    // }
                    
                    int* n1=arr1+m*COLOUMS+i;
                    int* n2=arr2+i*ROW+n;
                    //printf("n1=%d\tn2=%d\n",*n1,*n2);
                    a+=(*n1)*(*n2);
                }
                int* p=arr3+m*ROW+n;
                *p=a;
                //printf("n=%d,m=%d,value=%d\n",n,m,*p);
                //arr3[m][n]=arr1[m][1..3]+arr2[1..3][n];
            }
        }

        //print
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < ROW; j++)
            {
                int* p=arr3+i*ROW+j;
                if (j==0)
                {
                    printf("%d",*p);
                }else{
                    printf(" %d",*p);
                }
                
                
            }
            printf("\n");
        }
        
        
    }
    
    
}