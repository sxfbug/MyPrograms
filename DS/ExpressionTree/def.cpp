#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include"tree.hpp"

//parentheses 括号

//逻辑：先将中缀转换为后缀，然后用表达式树存储

//先构建优先级最高（最先计算）的子树，再把子树接到根结点
//ds说的思路，就是中序遍历序列构造二叉树?

//从中缀表达式转换为树
//参数：表达式  string
//返回值：树的结点指针TreeLink


ExpressionTree::TreeLink ExpressionTree::exchange_mid_to_tree(string x){
    
    
    ExpressionTree::TreeLink node=new ExpressionTree::TreeNode("null");


    //遍历检查是否没有运算符
    //不是符号，就是操作数，把数存到结点里
    //数一定是叶子结点
    //并且检查括号，如果括号位于首尾两端，则去除
    bool is_oprand=false;
    int pos_left_parenthese=5,pos_right_parenthese=5;
    for (int i = 0; i < x.size(); i++)
    {
        //check parenthese
        if (x[i]=='(')
        {
            pos_left_parenthese=i;
            continue;
        }

        if (x[i]==')')
        {
            pos_right_parenthese=i;
            continue;
        }
        
        //check oprands
        if (x[i]=='+' || x[i]=='*'||x[i]=='-'||x[i]=='/')
        {
            is_oprand=true;
            break;
        }
        
    }
    
    //检查并删除括号
    if (pos_left_parenthese==0 && pos_right_parenthese==x.size()-1)
    {
        x=x.substr(pos_left_parenthese+1,x.size()-1);
    }
    
    //如果没有，就直接添加到结点
    if (!is_oprand)
    {
        node->data=x;
        return node;
    }
    

    //开始正式递归
    int pos;

    //+ -
    //从末尾向前，反向遍历，可以保证运算的左结合性
    for (int i = x.length()-1; i >=0 ; i--)
    //for (int i = 0; i <x.length() ; i++)
    {
        
        pos=i;
        if (x[i]=='+')
        {
            
            //根节点
            node->data="+";
            node->lchild=exchange_mid_to_tree(x.substr(0,pos));
            node->rchild=exchange_mid_to_tree(x.substr(pos+1,x.size()));
            return node;
        }
        
        if (x[i]=='-')
        {
            
            //根节点
            node->data="-";
            node->lchild=exchange_mid_to_tree(x.substr(0,pos));
            node->rchild=exchange_mid_to_tree(x.substr(pos+1,x.size()));
            return node;
        }
        
        
    }

    //处理乘法，优先级更高，靠后处理
    //必须在加法处理完成后再处理乘法
    for (int i = x.length()-1; i >=0 ; i--)
    //for (int i = 0; i < x.size(); i++)
    {
        if (x[i]=='*')
        {
            pos=i;
            node->data="*";
            node->lchild=exchange_mid_to_tree(x.substr(0,pos));
            node->rchild=exchange_mid_to_tree(x.substr(pos+1,x.size()));
            return node;
        }

        if (x[i]=='/')
        {
            pos=i;
            node->data="/";
            node->lchild=exchange_mid_to_tree(x.substr(0,pos));
            node->rchild=exchange_mid_to_tree(x.substr(pos+1,x.size()));
            return node;
        }
    }
   
    
    return node;
}


//通过后序遍历表达式树，进行结果的计算
//参数：表达式树的引用
//返回值：结果 double
double ExpressionTree::calculate(ExpressionTree::TreeLink &x){
        //用一个栈辅助
        //操作数压栈，运算符则弹出两个操作数，运算后再把结果入栈
        
        
        stack<string> sup;
        internal_backtrace_visit(x,sup);
        //此时栈中的元素就是结果
        string result=sup.top();
        return stod(result);
        
    
    }


    void ExpressionTree::internal_backtrace_visit(ExpressionTree::TreeLink &x,stack<string> &sup)
    {
    if (x!=nullptr)
    {
        internal_backtrace_visit(x->lchild,sup);
        internal_backtrace_visit(x->rchild,sup);
        //操作数压栈，运算符则弹出两个操作数，运算后再把结果入栈
        if (x->data=="+"||x->data=="*"||x->data=="/"||x->data=="-")
        {
            //pop 2 oprands
            //先弹一个，再读取下一个
            string op2=sup.top();
            sup.pop();
            string op1=sup.top();
            sup.pop();

            //calculate
            if (x->data=="+")
            {
                op1= to_string(stoi(op1)+stoi(op2));
            }else if (x->data=="-"){
                op1= to_string(stoi(op1)-stoi(op2));
            }else if (x->data=="*"){
                op1= to_string(stoi(op1)*stoi(op2));
            }else if (x->data=="/"){
                op1= to_string(stoi(op1)/(double)stoi(op2));
            }
            
            //push back
            sup.push(op1);
            //cout<<"push back: "<<op1<<endl;
        }
        else{
            sup.push(x->data);
            //cout<<"push: "<<x->data<<endl;
        }
    }
    }