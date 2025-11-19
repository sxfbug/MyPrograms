#include<stdio.h>
#include<malloc.h>

int main(){
    int dim,i,j;
    while (scanf("%d",&dim)!=EOF)
    {
        int* arr=(int*)malloc(sizeof(int)*dim*dim);

        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                scanf("%d",arr+j*dim*sizeof(int)+i*sizeof(int));
            }
            
        }

        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                int re=*(arr+i*dim*sizeof(int)+j*sizeof(int));
                if (j==0)
                {
                    printf("%d",re);
                }else{
                    printf(" %d",re);
                }
                
                
            }
            printf("\n");
            
        }
        
        free(arr);
    }
    
    
    
    
}