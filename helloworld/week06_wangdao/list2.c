#include<stdio.h>
#include<malloc.h>


typedef struct list
{
    int data;
    struct list *prev;
    struct list *next;
}list;
int main(){
    int x;
    list* dummy=(list*)malloc(sizeof(list));
    dummy->data=-1;
    dummy->prev=NULL;
    dummy->next=NULL;
    list* nextnode=dummy;

    scanf("%d",&x);
    while (x>=0)
    {
        list* newnode=(list*)malloc(sizeof(list));
        newnode->data=x;

        newnode->next=NULL;

        newnode->prev=nextnode;
        nextnode->next=newnode;
 
        nextnode=newnode;

        scanf("%d",&x);
    }
    
    while (nextnode!=NULL && nextnode->data>=0)
    {
        printf("%d ",nextnode->data);
        nextnode=nextnode->prev;
    }
    




}