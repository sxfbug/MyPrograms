#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include"tree.hpp"


//层序遍历
void level_visit(ExpressionTree::TreeLink &x){
    queue<ExpressionTree::TreeLink> sup;
    if (x==nullptr)
    {
        cout<<"node is empty.";
        return;
    }

    sup.push(x);

    while (!sup.empty())
    {
        ExpressionTree::TreeLink head=sup.front();
        sup.pop();
        //visit node
        cout<<head->data<<"\t";

        //add children node
        if (head->lchild!=nullptr)
        {
            sup.push(head->lchild);
        }
        if (head->rchild!=nullptr)
        {
            sup.push(head->rchild);
        }
        
        

    }
    
    
}

//后序遍历
void backtrace_visit(ExpressionTree::TreeLink &x){
    if (x!=nullptr)
    {
        backtrace_visit(x->lchild);
        backtrace_visit(x->rchild);
        cout<<x->data<<"\t";
    }
    
}