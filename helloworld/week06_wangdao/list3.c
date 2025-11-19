#include<stdio.h>
#include<malloc.h>

typedef struct linklist
{
    int data;
    struct linklist* pointer;
}list;

int main(){
    int x,target;
    //指向父结点
    
    list* dummy=(list*)malloc(sizeof(list));
    //指向下一个插入位置
    list* next=dummy;
    scanf("%d",&x);
    while (x>=0)
    {
        list* xnew=(list*)malloc(sizeof(list));
        xnew->data=x;
        xnew->pointer=NULL;

        //先访问的是pointer,所以要确保第一次访问的是合法内存
        next->pointer=xnew;
        next=xnew;
        

        scanf("%d",&x);
    }
    
    scanf("%d",&target);
    while (dummy->pointer!=NULL)
    {
        if (dummy->pointer->data>target)
        {
            printf("%d ",dummy->pointer->data);
        }
        
        
        dummy=dummy->pointer;

    }
    


}