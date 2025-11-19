#include<stdio.h>
#include<malloc.h>
int main(){
    int n,i;

    scanf("%d",&n);
    int *y=(int*)malloc(sizeof(int)*n);
    int *q=(int*)malloc(sizeof(int)*n);
    float *e=(float*)malloc(sizeof(float)*n);
    float *f=(float*)malloc(sizeof(float)*n);
    float *g=(float*)malloc(sizeof(float)*n);
    float *s1=(float*)malloc(sizeof(float)*n);
    float *s2=(float*)malloc(sizeof(float)*n);
     

    for(int i=0;i<n;i++){
        scanf(" %d %d %f %f %f",&y[i],&q[i],&e[i],&f[i],&g[i]);
        float q_days=y[i]*(1+e[i]/q[i]*q[i]/365);
        s1[i]=q_days*(1+g[i]/100);
        s2[i]=y[i]*(1+f[i]/q[i]*(q[i]+365)/365);
        
    }
    for(int i=0;i<n;i++){
        printf("y=%d,q=%d,e=%.2f,f=%.2f,g=%.2f\n",y[i],q[i],e[i],f[i],g[i]);
        
    }
    for(int i=0;i<n;i++){
        printf("%.1f\n",s1[i]);
        printf("%.1f\n",s2[i]);
    }
    free(y);
    free(q);
    free(e);
    free(f);
    free(g);
    free(s1);
    free(s2);
    
}