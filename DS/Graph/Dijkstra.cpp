#include<iostream>
#include<vector>
#include<queue>
#include"graph.hpp"

void dijk(Matrix_DirectedGraph_Weighted &x,int start){
    //初始化 是否找到最短路径、最短路径长度、路径前驱 数组
    vector<bool> is_done(x.getsize(),false);
    vector<int> dist(x.getsize(),-1);
    vector<int> prev(x.getsize(),-1);

    //从起始结点开始
    is_done[start]=true;
    dist[start]=0;
    prev[start]=-2;
    //遍历相邻结点并更新dist
    for (int i = 0; i < x.getsize(); i++)
    {
        //如果相邻，更新dist和prev
        if (x.getgraph()[start][i]!=0)
        {
            dist[i]=x.getgraph()[start][i];   
            prev[i]=start;
        }
          

    }

    //遍历剩余结点
    for (int i = 1; i < x.getsize(); i++)
    {
        //对于dist最小且未找到最短路径的结点
        //返回当前最小元素的索引
        int min=find_min(dist,is_done);
        
        
        //当前为最短路径
        is_done[min]=true;
            //检验当前结点的引入是否会给其他邻接结点带来更短的路径
            for (int j = 0; j < x.getsize(); j++)
            {
                //如果单纯比大小，因为我初始值是-1,一定是最小的，所以不能满足条件
                //需要再加上一个-1的条件判断，代表这个点是尚未连接的，也需要进行判断
                if (x.getgraph()[min][j]>0 && (dist[j]==-1 || dist[j] > dist[min]+x.getgraph()[min][j]))
                {
                    dist[j]=dist[min]+x.getgraph()[min][j];
                    prev[j]=min;
                }
                
            }
            
        
        }
        cout<<"dist arrray: "<<endl;
        pri_vec(dist);
        cout<<"prev array: "<<endl;
        pri_vec(prev);
        cout<<"is_done array: "<<endl;
        pri_vec(is_done);
    }
    
    


//遍历dist数组，找到dist最小且flag为false（未被访问过）的结点
//参数：vector int
//返回值：int索引
int find_min(vector<int> &x,vector<bool> &flag){
    if (x.empty())
    {
        cout<<"vector is empty";
        return 0;
    }
    bool flag1=false;
    int min=-1;
    //寻找dist最小且大于0的
    for (int i = 0; i < x.size(); i++)
    {    
        if (x[i]>0 && flag[i]==false)
        {
            if (min==-1)
            {
                min=i;
            }
            
            min=x[min]<x[i] ? min : i;
            flag1=true;
        }
        
        
    }
    if (flag1==false)
    {
        cout<<"none node is connected\n";
        return 0;
    }
    
    return min;
      
}


