#include"headfile.hpp"

//通过递归关系，实现结点之间父子关系的链接
BSTLink BST_build(BSTLink &root,int data)
{
    //递归停止的条件：遇到空结点，说明到达了叶子的下端，就是新结点的所在地
    if (root==nullptr)
    {
        BSTLink newnode=new BSTNode;
        newnode->data=data;
        newnode->lchild=nullptr;
        newnode->rchild=nullptr;
        return newnode;
    }
    
    //进行比较
    if (data > root->data)
    {
        root->rchild=BST_build(root->rchild,data);
    }
    else if (data < root->data)
    {
        root->lchild=BST_build(root->lchild,data);
    }
    else{
        cout<<"value is equal";
        return root;
    }
    return root;
    
}


//参数：x被检查的当前结点，t删除的值，prev找到的结点的前驱，now查找到的结点
void BST_search(BSTLink &x,int t,BSTLink &prev,BSTLink &now)
{
    if (x==nullptr)
    {
        cout<<"bst search: dont have this value";
        return;
    }
    
    if (t < x->data)
    {
        prev=x;
        //path.push_back(true);
        BST_search(x->lchild,t,prev,now);
        
    }
    else if(t>x->data)
    {
        prev=x;
        //path.push_back(false);
        BST_search(x->rchild,t,prev,now);
        
    }else{
        
        cout<<"bst search: finded\n";
        now=x;
        
    }
    return;
}


//t要删除的结点值
void BST_delete(BSTLink &x,int t)
{
    //分三种情况
    //删除的是叶子，删除的结点只有左或右孩子，删除的结点有两个孩子
    BSTLink now=nullptr,pre=nullptr;
    BST_search(x,t,pre,now);
    //被删除的结点不存在
    if (now==nullptr)
    {
        /* code */
        cout<<"node that need to be deleted is not exist.";
        return;
    }
    
    //是叶子结点，直接删除
    if (now->lchild==nullptr && now->rchild==nullptr)
    {
        
        if (pre!=nullptr)
        {
            if (pre->rchild==now)
            {
                pre->rchild=nullptr;
            }else{
                pre->lchild=nullptr;
            }           
        }
        

        
        delete now;
        return;
    }
    
    //只有左or右孩子，直接顶替
    //交接前驱关系
    if (now->lchild==nullptr && now->rchild!=nullptr)
    {
        if (pre!=nullptr)
        {
            if (pre->lchild==now)
            {
                pre->lchild=now->rchild;
                
            }
            else{
                pre->rchild=now->rchild;
            }
            delete now;
            
        }
        //前驱为空，删除的是root
        else{
            BSTLink temp=x;
            x=x->rchild;
            delete temp;
        }
        return;
    }
    else if (now->lchild!=nullptr && now->rchild==nullptr)
    {
        if (pre!=nullptr)
        {
            if (pre->lchild==now)
            {
                pre->lchild=now->lchild;
            }
            else{
                pre->rchild=now->lchild;
            }
            delete now;
            
        }
        //前驱为空，删除的是root
        else{
            BSTLink temp=x;
            x=x->lchild;
            delete temp;
        }
        return;
    }

    //有两个孩子，找中序后继替代
    //右子树的最左叶子
    if (now->lchild!=nullptr && now->rchild!=nullptr)
    {
        BSTLink replace=spe_midorder(now->rchild);
        now->data=replace->data;
        BST_delete(now->rchild,replace->data);
        return;
    }
    
    
}