#ifndef TREE
#define TREE

#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

class ExpressionTree{
    private:
        
        

    public:
    //树结点结构体
        typedef struct TreeNode{
            string data;
            struct TreeNode* lchild;
            struct TreeNode* rchild;
            TreeNode(string x):data(x),lchild(nullptr),rchild(nullptr){};
        }*TreeLink;
    
    //表达式树的根结点
        TreeLink root;


    //function defination


    //从中缀表达式转换为树,从字符串构造树，递归函数
    //参数：表达式  string
    //返回值：树的结点指针TreeLink
    TreeLink exchange_mid_to_tree(string x);


    //后序遍历并进行求值
    //参数：表达式树的结点
    //返回值：计算结果
    double calculate(TreeLink &x);

    void internal_backtrace_visit(ExpressionTree::TreeLink &x,stack<string> &sup);
        
    
    




};



//函数定义

//support
void level_visit(ExpressionTree::TreeLink &x);
void backtrace_visit(ExpressionTree::TreeLink &x);




#endif