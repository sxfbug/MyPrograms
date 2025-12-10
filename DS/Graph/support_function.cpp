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



//关键路径里的dfs,找最长的关键路径
//参数：收集全部关键路径的二维vector,记录所有关键活动的vector,起点
void cp_dfs_full(vector<vector<tuple<int,int,int>>> &all_ce,vector<tuple<int,int,int>> &critical_edge,int start)
{

    //先找到起点和相连的关键活动
    for (int i = 0; i < critical_edge.size(); i++)
    {
        //一条dfs关键路径，首元素的第一个维度来记录边的总权值
        vector<tuple<int,int,int>> path;
        tuple<int,int,int> dummy(0,0,0);
        path.push_back(dummy);
        bool is_end=false;
        //找到起点后，沿着边寻找下一个顶点，和下一条边
        //传当前的弧尾作为参数，来继续寻找
        if (get<1>(critical_edge[i])==start)
        {
            //添加到关键路径vector中
            path.push_back(critical_edge[i]);
            //更新总长
            get<0>(path[0])+=get<0>(critical_edge[i]);

            //进行下一层调用
            cp_dfs(critical_edge,path,get<2>(critical_edge[i]),is_end);
            
        }

        //完成这一条dfs路径后，记录到all_ce里面
        all_ce.push_back(path);
        
    }
    
}

//参数：关键活动集合，下一个要找的弧头
void cp_dfs(vector<tuple<int,int,int>> critical_edge,
    vector<tuple<int,int,int>> path,int head,bool is_end)
{
    if (is_end)
    {
        return;
    }
    
    //到汇点了，退出所有的cp_dfs循环
    if (head==get<2>(critical_edge.back()))
    {
        is_end=true;
        return;
    }
    
    for (int i = 0; i < critical_edge.size(); i++)
    {
        //找到了
        if (get<1>(critical_edge[i])==head)
        {
            //添加到关键路径vector中
            path.push_back(critical_edge[i]);
            //更新总长
            get<0>(path[0])+=get<0>(critical_edge[i]);

            //下一层调用
            cp_dfs(critical_edge,path,get<2>(critical_edge[i]),is_end);
        }
        
    }
    //如果找不到，说明到了最后一个？
    
    //需要一个visited数组来记录是否访问过，
    //因为对于a-b-c(b-d)这种路径，b-d的分支是不会被遍历到的

}