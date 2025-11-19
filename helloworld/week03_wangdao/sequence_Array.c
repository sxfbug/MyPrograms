#include<stdio.h>
#include<malloc.h>

int main(){
    int sizea,sizeb,i;
    int sizeall;
    int pa=0,pb=0;

    //get array a
    while(scanf("%d",&sizea)!=EOF){
    int* a=(int*)malloc(sizeof(int)*sizea);
    for (int i = 0; i < sizea; i++)
    {
        scanf("%d",&a[i]);
    }
    
    //get array b
    scanf("%d",&sizeb);
    int* b=(int*)malloc(sizeof(int)*sizeb);
    for (int i = 0; i < sizeb; i++)
    {
        scanf("%d",&b[i]);
    }

    //get array all
    sizeall=sizea+sizeb;
    int* all=(int*)malloc(sizeof(int)*sizeall);

    //快慢指针
    for (int i = 0; i < sizeall; i++)
    {   
        if (pa<sizea&&pb<sizeb)
        {
            if (a[pa]<=b[pb])
            {
                all[i]=a[pa];
                pa++;
            }else if(a[pa]>b[pb]){
                all[i]=b[pb];
                pb++;
            }
        }else if(pa>=sizea&&pb<sizeb){
            all[i]=b[pb];
            pb++;
        }else if(pb>=sizeb&&pa<sizea){
            all[i]=a[pa];
            pa++;
        }
        
        
        
        
    }
    


    //print out
    for (int i = 0; i < sizeall; i++)
    {
      	if(i==0){
        printf("%d",all[i]);
        }else{
        printf(" %d",all[i]);
        }
        /* code */
    }
    printf("\n");
}
    
}