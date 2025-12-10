#include"headfile.hpp"

//四种旋转
//返回值：返回调整好的子树root
//因为要调整最小子树，所以也在插入的递归栈返回的时候（自底向上），顺便调整了,因此不需要找前缀
AVLLink AVL_adjust(AVLLink &x)
{
    //处理空指针
    if (x==nullptr)
    {
        return nullptr;
    }
    
    //0,1,-1是被允许的情况
    if (x->balanced < 2 && x->balanced > -2)
    {
        return x;
    }

    //LL
    if(x->balanced==2 && x->lchild->balanced==1)
    {
        /*
            x
            /\
          nr  t1
          /\
        ls t2
        /\
      t3 t4 
        */
        AVLLink t1=x->rchild,nr=x->lchild,ls=nr->lchild,
        t2=nr->rchild;
        //rotate
        t2=x->lchild;
        x=nr->rchild;
        return nr;
    }
    
    //RR
    if (x->balanced==-2 && x->rchild->balanced==-1)
    {
        /*
            x
            /\
          t1  nr
              /\
             t2 ls
                /\
               t3 t4 
        */
        AVLLink nr=x->rchild,ls=nr->rchild,
        t1=x->lchild,t2=nr->lchild;
        x->rchild=t2;
        nr->lchild=x;
        return nr;
    }
    
    //LR
    if (x->balanced==2 && x->lchild->balanced==-1)
    {
        /*
            x
            /\
          mid  t1
          /\
         t2 ls
            /\
           t3 t4 
        */
        //nr<ls<x ,新的根的值是ls的值
        AVLLink mid=x->lchild,ls=mid->rchild,t4=ls->rchild,t3=ls->lchild,t2=mid->lchild;
        //switch mid and ls
        int temp=mid->data;
        mid->data=ls->data;
        ls->data=temp;
        //rotate
        x->lchild=t4;
        ls->rchild=t3;
        ls->lchild=t2;
        mid->rchild=x;
        mid->lchild=ls;

        return mid;
    }
    
    //RL
    if (x->balanced==-2 && x->rchild->balanced==1)
    {
        /*
            x
            /\
          t1  mid
              /\
             ls t2
             /\
           t3 t4 
        */
      AVLLink  mid=x->rchild,ls=mid->lchild,t3=ls->lchild,t4=ls->rchild,t2=mid->rchild;
        //switch value
        int temp=mid->data;
        mid->data=ls->data;
        ls->data=temp;
        //rotate
        x->rchild=t3;
        ls->lchild=t4;
        ls->rchild=t2;
        mid->lchild=x;
        mid->rchild=ls;
        return mid;
    }
    
}

//update更新树高，中序遍历
//递归更新，自底向上更新
AVLLink AVL_update(AVLLink &x)
{
    
    //左右孩子都是空，x是叶子结点
    if (x->lchild==nullptr && x->rchild==nullptr)
    {
        x->balanced=0;
        x->height=1;
    }
    //只有左or右孩子
    else if(x->lchild!=nullptr && x->rchild==nullptr)
    {
        x->balanced=x->lchild->balanced+1;
        x->height=x->lchild->height+1;
    }
    else if(x->lchild==nullptr && x->rchild!=nullptr)
    {
        x->balanced=x->rchild->balanced-1;
        x->height=x->rchild->height+1;
    }
    //有左右孩子
    else{
        //高度取左右孩子最大的那个
        x->height= (x->lchild->height > x->rchild->height) ? 
        (x->lchild->height +1) : (x->rchild->height +1);

        x->balanced=x->lchild->height - x->rchild->height;
    }
    return x;
}

//build构建avl
AVLLink AVL_build(AVLLink &x,int t)
{
    //找到要插入的空间了，执行插入
    if (x==nullptr)
    {
        AVLLink newnode=new AVLNode;
        newnode->data=t;
        newnode->lchild=nullptr;
        newnode->rchild=nullptr;
        newnode->balanced=0;
        newnode->height=1;
        x=newnode;
    }
    
    //对比大小并插入
    if (t > x->data)
    {
        x->rchild=AVL_build(x->rchild,t);
    }
    else if(t < x->data){
        x->lchild=AVL_build(x->lchild,t);

    }else if(t==x->data){
        //cout<<"avl build: value equal. data: "<<x->data<<endl;
    }
    /*
    else{
        cout<<"avl build: unexcepted branch in comparing value.";
        return nullptr;
    }
    */

    
    //比较完成，更新平衡因子后，返回当前结点
    
    x=AVL_update(x);
    x=AVL_adjust(x);
    return x;
}