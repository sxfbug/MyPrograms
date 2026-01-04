#include"headfile.hpp"


//BST树的先中后序遍历

void preorder(BSTLink &x)
{
    if (x!=nullptr)
    {
        cout<<"preorder visited: "<<x->data<<endl;
        preorder(x->lchild);
        preorder(x->rchild);
    }
    
}

void midorder(BSTLink &x)
{
    if (x!=nullptr)
    {          
        midorder(x->lchild);
        cout<<"midorder visited: "<<x->data<<endl;
        midorder(x->rchild);
    }
}

void lastorder(BSTLink &x)
{
    if (x!=nullptr)
    {       
        lastorder(x->lchild);
        lastorder(x->rchild);
        cout<<"lastorder visited: "<<x->data<<endl;
    }
}
//AVL树的先中后序遍历

void preorder(AVLLink &x)
{
    if (x!=nullptr)
    {
        cout<<"preorder visited: "<<x->data<<endl;
        preorder(x->lchild);
        preorder(x->rchild);
    }
    
}

void midorder(AVLLink &x)
{
    if (x!=nullptr)
    {          
        midorder(x->lchild);
        cout<<"midorder visited: "<<x->data<<endl;
        midorder(x->rchild);
    }
}

void lastorder(AVLLink &x)
{
    if (x!=nullptr)
    {       
        lastorder(x->lchild);
        lastorder(x->rchild);
        cout<<"lastorder visited: "<<x->data<<endl;
    }
}
//BST层序遍历
void layerorder(BSTLink &x)
{
    queue<BSTLink> sup;
    if(x==nullptr)
    {
        cout<<"layerorder:nullptr";
        return;
    }
    sup.push(x);

    //初始化：done=0，curr=1
    //done记录已经当前层出队的结点数，curr记录当前层需要出队的结点数,next记录下一层需要出队的结点数
    //done==curr说明完成当前层遍历，输出\n，done=0,传递下一层的遍历信息curr=next
    //当上一层有一个孩子时，next+=1
    int done=0,curr=1,next=0;
    while (!sup.empty())
    {
        BSTLink head=sup.front();

        sup.pop();
        done+=1;
        cout<<head->data<<"  ";
        
        

        

        if (head->lchild!=nullptr)
        {
            sup.push(head->lchild);
            next+=1;
        }
        if (head->rchild!=nullptr)
        {
            sup.push(head->rchild);
            next+=1;
        }

        if (done==curr)
        {
            cout<<endl;
            done=0,curr=next,next=0;
        }

        
        
    }
    
}

//AVL层序遍历
void layerorder(AVLLink &x)
{
    queue<AVLLink> sup;
    if(x==nullptr)
    {
        cout<<"layerorder:nullptr";
        return;
    }
    sup.push(x);

    //初始化：done=0，curr=1
    //done记录已经当前层出队的结点数，curr记录当前层需要出队的结点数,next记录下一层需要出队的结点数
    //done==curr说明完成当前层遍历，输出\n，done=0,传递下一层的遍历信息curr=next
    //当上一层有一个孩子时，next+=1
    int done=0,curr=1,next=0;
    while (!sup.empty())
    {
        AVLLink head=sup.front();

        sup.pop();
        done+=1;
        cout<<head->data<<"(Balanced: "<<head->balanced<<" Height: "
        <<head->height<<")  ";
        
        

        

        if (head->lchild!=nullptr)
        {
            sup.push(head->lchild);
            next+=1;
        }
        if (head->rchild!=nullptr)
        {
            sup.push(head->rchild);
            next+=1;
        }

        if (done==curr)
        {
            cout<<endl;
            done=0,curr=next,next=0;
        }

        
        
    }
    
}

//spe 遍历
//参数：x是当前遍历结点，pre是结点的前驱
//返回值：第一个找到的最左的非空叶子结点
BSTLink spe_midorder(BSTLink &x)
{
    if(x == nullptr) {
        return nullptr;
        }
    if(x!=nullptr){
        //pre=x;
        if(x->lchild==nullptr){
            return x;
        }else{
            return spe_midorder(x->lchild);
        }
        

    }
}

BSTLink spe_backorder(BSTLink &x,BSTLink &pre)
{
    if(x!=nullptr){
        pre=x;
        spe_backorder(x->rchild,x);

    }else{
        return x;
    }
}

//找中序后继用的，返回最左的叶子结点
AVLLink spe_inorder(AVLLink x,AVLLink &pre)
{
    if (x==nullptr)
    {
        return nullptr;
    }
    
    while (x->lchild)
    {
        pre=x;
        x=x->lchild;
    }
    return x;
    
}

//遍历vector
void pri_vec(vector<bool> &a)
{
    cout<<endl;
    for (bool i : a)
    {
        cout<<i<<"\t";
    }
    cout<<endl;
}