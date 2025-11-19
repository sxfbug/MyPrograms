
#include<iostream>
#include<vector>
#include<queue>
#include"graph.hpp"

//辅助函数

//遍历打印vector
void pri_vec(vector<bool> &x){
    cout<<endl;
    for (int i = 0; i <x.size(); i++)
    {
        cout<<"index: "<<i<<"\telement: "<<x[i]<<"\n";
    }
        cout<<endl;

}

void pri_vec(vector<int> &x){
    cout<<endl;
    for (int i = 0; i <x.size(); i++)
    {
        cout<<"index: "<<i<<"\telement: "<<x[i]<<"\n";
    }
        cout<<endl;

}


//遍历打印二维vector

void pri_vec(vector<vector<int>> &x){
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x.size(); j++)
        {
            cout<<"x["<<i<<"]["<<j<<"]= "<<x[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
}