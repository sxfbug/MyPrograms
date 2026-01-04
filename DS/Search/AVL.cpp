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
    //lchild的平衡因子，在插入时只会是1,但在删除时可能是0
    if(x->balanced==2 && x->lchild->balanced>=0)
    {
        return LL(x);
    }
    
    //RR
    if (x->balanced==-2 && x->rchild->balanced<=0)
    {
        return RR(x);
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
        x->lchild=RR(x->lchild);
        
        return LL(x);
        
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
        x->rchild=LL(x->rchild);
        return RR(x);
    }
    
}

//update更新树高，中序遍历
//递归更新，自底向上更新
AVLLink AVL_update(AVLLink &x)
{
    if (x==nullptr)
    {
        return x;
    }
    
    //先计算左右孩子的树高
    //如果左孩子存在，则树高为孩子的树高，如果不存在，则为0
    int left_height= (x->lchild) ? x->lchild->height : 0;
    int right_height=(x->rchild) ? x->rchild->height : 0;

    x->height= (left_height > right_height) ? (left_height+1) : (right_height+1);
    x->balanced=left_height-right_height;

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

//删除
//参数：结点所在的树，要删除的值
//返回值：返回当前结点，不管是否调整
//recursion递归，因为update和adjust是依赖递归实现的
AVLLink AVL_delete(AVLLink &x,int t)
{
    //先找到，再删除，最后调整
    //处理空指针，显然是找不到的情况了
    if (x==nullptr)
    {
        return nullptr;
    }
    
    if (t < x->data)
    {
        x->lchild=AVL_delete(x->lchild,t);
        x=AVL_update(x);
        x=AVL_adjust(x);
    }
    else if (t > x->data)
    {
        x->rchild=AVL_delete(x->rchild,t);
        x=AVL_update(x);
        x=AVL_adjust(x);
    }
    //找到了,x是要删除的结点
    else
    {
        //三种情况：无孩子，只有一孩，有二孩
        //无孩
        if (x->lchild==nullptr && x->rchild==nullptr)
        {
            AVLLink re=x;
            delete re;
            x=nullptr;
            
        }
        //二孩,找中序后继代替
        //找中序后继的函数，同时需要找中序后继的父节点，
        //因为如果删除导致不平衡，它就是最小不平衡子树的根
        else if (x->lchild && x->rchild)
        {
            AVLLink pre=nullptr;
            AVLLink target=spe_inorder(x->rchild,pre);
            //交接值，并递归删除该结点
            x->data=target->data;
            x->rchild=AVL_delete(x->rchild,target->data);
        }
        //一孩
        else if (x->lchild)
        {
            AVLLink re=x;
            x=x->lchild;
            delete re;
            
        }
        else if (x->rchild)
        {
            AVLLink re=x;
            x=x->rchild;
            delete re;
            
        }
        //完成所有的删除后，更新结点
        x=AVL_update(x);
        x=AVL_adjust(x);
        
        
    }
    
    return x;
}

//查找
//参数：root,查找的值
//返回值：值相等结点的指针，找不到返回nullptr
AVLLink AVL_search(AVLLink &x, int t)
{
    //处理空指针，显然是找不到的情况了
    if (x==nullptr)
    {
        return nullptr;
    }
    
    if (x->data==t)
    {
        return x;
    }
    else if (t < x->data)
    {
        //pre=x;
        return AVL_search(x->lchild,t);
    }
    else if (t > x->data)
    {
        //pre=x;
        return AVL_search(x->rchild,t);
    }
    
    
    
}
//rotate function
//输入：需要调整的根结点
//输出：调整后的根结点
AVLLink RR(AVLLink &x)
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
   AVLLink nr=x->rchild;
   x->rchild=nr->lchild;
   nr->lchild=x;
   x=AVL_update(x);
   nr=AVL_update(nr);
   return nr;
}

AVLLink LL(AVLLink &x)
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
    AVLLink nr=x->lchild;
    x->lchild=nr->rchild;
    nr->rchild=x;
    x=AVL_update(x);
    nr=AVL_update(nr);
    return nr;
}