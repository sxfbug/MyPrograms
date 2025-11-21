#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include"tree.hpp"


int main(){
    ExpressionTree x;
    
    //level_visit(x.root);


    string b;
    cout<<"\n请输入表达式: ";
    
    while (cin >> b)
    {
        x.root=x.build_child_tree(b);

        level_visit(x.root);
        cout<<endl;
        backtrace_visit(x.root);
        cout<<endl;
        int result=x.calculate(x.root);
        cout<<result;

        cout<<"\n请输入表达式: ";
    }  

    
    
}