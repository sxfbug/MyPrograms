#include"headfile.hpp"

RBTLink RBT_build(RBTLink &root,RBTLink pre,int t)
{
    //找到空结点，插入
    if (root==nullptr)
    {
        RBTLink newnode=new RBTNode;
        newnode->data=t;
        newnode->lchild=nullptr;
        newnode->rchild=nullptr;
        newnode->parent=pre;
        //新结点一定是红色的
        newnode->color=RED;
        root=newnode;
        root=RBT_adjust(root);
        return root;
    }
    RBTLink newchild=nullptr;
    if (t < root->data)
    {
        pre=root;
        
        newchild=RBT_build(root->lchild,pre,t);
        //如果原本的孩子和新孩子不相等，说明发生了旋转
        if (root->lchild!=newchild)
        {
            root->lchild=newchild;
        }
        
    }
    else if (t > root->data)
    {
        pre=root;
        newchild=RBT_build(root->rchild,pre,t);     
        //如果原本的孩子和新孩子不相等，说明发生了旋转
        if (root->rchild!=newchild)
        {
            root->rchild=newchild;
        }  
    }
    //相等
    else{
        return root;
    }
    //返回当前结点
    root=RBT_ad2(root);
    return root;
}

RBTLink RBT_adjust(RBTLink &root)
{
    //开始变色
    //根节点，一定是黑色
    if(root==nullptr){
        return nullptr;
    }
    if(root->parent==nullptr)
    {
        root->color=BLACK;
        return root;
    }
    
    //自己和父亲是红色
    else if (root->color==RED && root->parent->color==RED)
    {
        //看祖父是否存在
        RBTLink gparent=root->parent->parent;
        if (gparent)
        {
            //祖父存在，看叔叔结点的颜色
            //如果左孩子是父亲，叔叔就是右孩子，反之亦然
            RBTLink cousin= (gparent->lchild==root->parent) ? gparent->rchild : gparent->lchild;
            //叔叔也是红色的
            if (cousin && cousin->color==RED)
            {
                //父亲和叔叔 和 祖父 交换颜色，祖父黑变红，父亲和叔叔红变黑
                //重新插入祖父结点
                if (gparent->color=RED)
                {
                    cout<<"err: grandparent is RED";
                    return nullptr;
                }
                gparent->color=RED;
                root->parent->color=BLACK;
                cousin->color=BLACK;
                RBT_adjust(gparent);
            }
            //叔叔是黑色的: 叔叔不存在（黑色叶子）或叔叔存在且是黑色
            else{
                //判断祖父、父亲、我的形状，进行四种旋转
                //LL
                
                if (gparent->lchild && gparent->lchild==root->parent && root->parent->lchild==root)
                {
                    root=LL(root);
                    //交换原祖父和父亲结点的颜色
                    Color temp=root->color;
                    root->color=root->rchild->color;
                    root->rchild->color=temp;
                }
                //RR
                if (gparent->rchild && gparent->rchild && gparent->rchild==root->parent && root->parent->rchild==root)
                {
                    root=RR(root);
                    //交换原祖父和父亲结点的颜色
                    Color temp=root->color;
                    root->color=root->lchild->color;
                    root->lchild->color=temp;
                }
                //LR
                if (gparent->lchild && gparent->lchild==root->parent && root->parent->rchild==root)
                {
                    root=RR(root);
                    root=LL(root);
                    //交换原祖父和父亲结点的颜色
                    Color temp=root->color;
                    root->color=root->rchild->color;
                    root->rchild->color=temp;

                }
                //RL
                if (gparent->rchild && gparent->rchild==root->parent && root->parent->lchild==root)
                {
                    root=LL(root);
                    root=RR(root);
                    //交换原祖父和父亲结点的颜色
                    Color temp=root->color;
                    root->color=root->lchild->color;
                    root->lchild->color=temp;
                }
            }
            
        }
        //祖父不存在，父亲是根结点
        //那父亲怎么会是红色？
        else{
            cout<<"err:root parent is RED.";
            root->parent->color=RED;
        }
        
    }
    return root;
}

//传入的参数是祖父结点
RBTLink RBT_ad2(RBTLink &gp)
{
    //判空
    if (gp==nullptr)
    {
        return nullptr;
    }
    
    //gp有两个孩子
    if (gp->lchild && gp->rchild)
    {
        RBTLink lc=gp->lchild,rc=gp->rchild;
        RBTLink son=nullptr,pp=nullptr,cousin=nullptr;
        //如果lc和lc的孩子都是红色
        //lc和rc的代码在一次插入中应该只会走一个分支，否则son等会被多次赋值
        //lc是红父
        if (lc->color=RED)
        {
            if (lc->lchild && lc->lchild->color==RED)
            {
                son=lc->lchild;
                pp=lc;
                cousin=rc;
            }
            else if (lc->rchild && lc->rchild->color==RED)
            {
                son=lc->rchild;
                pp=lc;
                cousin=rc;
            }
        }
        //rc是红父
        else if (rc->color=RED)
        {
            if (rc->lchild && rc->lchild->color==RED)
            {
                son=rc->lchild;
                pp=rc;
                cousin=lc;
            }
            else if (rc->rchild && rc->rchild->color==RED)
            {
                son=rc->rchild;
                pp=rc;
                cousin=lc;
            }
        }
        //处理父叔双红情况
        if (pp->color==RED && cousin->color==RED)
        {
            pp->color=BLACK;
            cousin->color=BLACK;
            gp->color=RED;
            //祖父结点变色后，要如何重新插入祖父结点？
            //或许不需要？等到遍历到祖父的祖父时就会自动调整？
        }
        //红父黑叔
        else if(pp->color==RED && cousin->color==BLACK)
        {
            RBTLink newnode=redparent_blackcousin(gp,pp,son);
            return newnode;
        }
        
    }
    //红父黑null叔情况
    //只有左孩子
    else if(gp->lchild){
        RBTLink pp=gp->lchild,son=nullptr;
        if (gp->lchild->lchild && gp->lchild->lchild->color==RED)
        {
            son=gp->lchild->lchild;
        }
        else if (gp->lchild->rchild && gp->lchild->rchild->color==RED)
        {
            son=gp->lchild->rchild;
        }
        RBTLink newnode=redparent_blackcousin(gp,pp,son);
        return newnode;
    } 
    //只有右孩子
    else if(gp->rchild){
        RBTLink pp=gp->rchild,son=nullptr;
        if (gp->rchild->lchild && gp->rchild->lchild->color==RED)
        {
            son=gp->rchild->lchild;
        }
        else if (gp->rchild->rchild && gp->rchild->rchild->color==RED)
        {
            son=gp->rchild->rchild;
        }
        RBTLink newnode=redparent_blackcousin(gp,pp,son);
        return newnode;
    }
    
}

RBTLink redparent_blackcousin(RBTLink &gp,RBTLink &pp,RBTLink &son)
{
    RBTLink newnode=nullptr;
    //判断gp,pp,son形状
    //LL
    if (gp->lchild==pp &&pp->lchild==son)
    {
        newnode=LL(son);
        //交换父亲和祖父的颜色
        Color temp=pp->color;
        pp->color=gp->color;
        gp->color=temp;
    }
    //RR
    else if (gp->rchild==pp &&pp->rchild==son)
    {
        newnode=RR(son);
        //交换父亲和祖父的颜色
        Color temp=pp->color;
        pp->color=gp->color;
        gp->color=temp;
    }
    //RL
    else if (gp->rchild==pp &&pp->lchild==son)
    {
        newnode=LL(son);
        newnode=RR(newnode);
        //交换颜色
        Color temp=son->color;
        son->color=gp->color;
        gp->color=temp;
  
    }
    //LR
    else if (gp->lchild==pp &&pp->rchild==son)
    {
        newnode=RR(son);
        newnode=LL(newnode);
        //交换颜色
        Color temp=son->color;
        son->color=gp->color;
        gp->color=temp;
    }
    return newnode;
}


RBTLink RBT_delete(RBTLink &root, int target)
{
    //删除，首先遵循bst规则
    if (root->data==target)
    {
        //三种情况，二孩，一孩，无孩
        
        //二孩
        if (root->lchild && root->rchild)
        {
            //找中序后继
            
        }
        //无孩
        else if(root->lchild==nullptr && root->rchild==nullptr)
        {
            //如果是红色结点，可以直接删除，不影响黑高
            if (root->color=RED)
            {
                root->parent=nullptr;
                delete root;
                return nullptr;
            }
            
            //如果是黑色结点，黑高-1,要看父亲的颜色
            else if (root->color=BLACK)
            {
                
            }
            
        }
        //一孩
        else if(root->lchild!=nullptr)
        {
             
        }
        else if(root->rchild!=nullptr)
        {

        }
    }
    else if(target < root->data)
    {
        root->lchild=RBT_delete(root->lchild,target);
    }
    else if(target > root->data)
    {
        root->rchild=RBT_delete(root->rchild,target);
    }
    return root;
}

RBTLink inorder_back(RBTLink &root,RBTLink &pre)
{
    while (root->lchild!=nullptr)
    {
        pre=root;
        root=root->lchild;
    } 
    return root;
    
}



//参数是插入的子结点
//返回的是，调整后的子树根节点
RBTLink LL(RBTLink &root)
{
    
    if (root==nullptr ||root->parent==nullptr|| root->parent->parent==nullptr)
    {
        return nullptr;
    }
    RBTLink pp=root->parent,gp=pp->parent;
    //AVL rotate
    gp->lchild=pp->rchild;
    pp->rchild=gp;
    //exchange parents pointer
    pp->parent=gp->parent;
    gp->parent=pp;
    if (gp->lchild)
    {
        gp->lchild->parent=gp;
    }
    
    

    return pp;
}

RBTLink RR(RBTLink &root)
{
    if (root==nullptr ||root->parent==nullptr|| root->parent->parent==nullptr)
    {
        return nullptr;
    }
    RBTLink pp=root->parent,gp=pp->parent;
    //AVL rotate
    gp->rchild=pp->lchild;
    pp->lchild=gp;
    //exchange parents
    pp->parent=gp->parent;
    gp->parent=pp;
    if (gp->rchild)
    {
        gp->rchild->parent=gp;
    }
    return pp;
}