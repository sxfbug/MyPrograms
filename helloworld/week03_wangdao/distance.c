#include<stdio.h>
#include<math.h>
#include<malloc.h>
double dis(int x1,int y1,int x2,int y2);
double dis(int x1,int y1,int x2,int y2){
    double a=x1-x2;
    double b=y1-y2;
    return sqrt((a*a+b*b));
}
int main(){
    int n;
    double re=0.0;
    scanf("%d",&n);
    int* x=(int*)malloc(sizeof(int)*n);
    int* y=(int*)malloc(sizeof(int)*n);
    
    for (int i = 0; i < n; i++)
    {
        /* code */
        scanf("%d %d",&x[i],&y[i]);
    }
    for (int i = 1; i < n; i++)
    {
        /* code */
        re+=dis(x[i-1],y[i-1],x[i],y[i]);
    }
    printf("%.2lf",re);

    
    free(x);
    free(y);
    
}