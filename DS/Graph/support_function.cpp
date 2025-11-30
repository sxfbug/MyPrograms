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
  
void pri_vec(vector<tuple<int,int,int>> &x)
{
    cout<<endl;

    for (int i = 0; i <x.size(); i++)
    {
        cout<<"index: "<<i<<"\t<0>: "<<get<0>(x[i])<<"\t<1>: "<<get<1>(x[i])<<"\t<2>: "<<get<2>(x[i])<<endl;
    }
        cout<<endl;

}





//遍历打印二维vector

void pri_vec(vector<vector<int>> &x){
    for (int i = 0; i < x.size(); i++)
    {
        for (int j = 0; j < x.size(); j++)
        {
            cout<<"x["<<i<<"]["<<j<<"]= "<<x[i][j]<<"\t";
        }
        cout<<endl;
        
    }
    
}



void pri_queue(queue<int> x){
    int n=x.size();
    for (int i = 0; i < n; i++)
    {
        int head=x.front();
        cout<<"x["<<i<<"]= "<<head<<endl;
        x.pop();
    }
    cout<<endl;
}


