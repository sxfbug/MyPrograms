#include"graph.hpp"

//TopologicalSorting
//功能：进行拓扑排序
//参数：邻接矩阵，有向
//返回值：排序结果，各结点的索引，int queue
vector<int> Topo(Matrix_DirectedGraph_Weighted &x)
{
    int n=x.getsize();
    stack<int> sup;
    vector<int> final;
    vector<int> indegree=x.get_indegree();
    //vector<bool> visited(n,false);
    
    bool has_cycle=true;

    //遍历寻找入度为0的结点开始
    for (int i = 0; i < n; i++)
    {
        if (indegree[i]==0)
        {
            has_cycle=false;
            sup.push(i);
            //visited[i]=true;
            
        }
        
    }
    //如果没有，说明存在环，退出
    if (has_cycle)
    {
        cout<<"Topa:this graph has a cycle.\n";
        return vector<int>();
    }

    while (!sup.empty())
    {
        //pop并入队
        int head=sup.top();
        sup.pop();
        final.push_back(head);

        //让head的相邻结点的入度-1
        //检查是否有符合条件的结点，进行入栈
        for (int i = 0; i < n; i++)
        {
            if (x.getgraph()[head][i]!=0)
            {
                indegree[i]-=1;
                if (indegree[i]==0)
                {
                    //visited[i]=true;
                    sup.push(i);
                }
            }
            
            
        }
        

    }
    
    //final check 
    //是否需要一个访问数组来记录结点访问情况？
    //不需要，通过入度来管理，每个结点只可能进入栈一次，如果存在环，环中的结点不会进入队列，不满足入度为0的条件

    if (final.size()!=n)
    {
        cout<<"Topa final:this graph has a cycle.\n";
        return vector<int>();
    }
    
    return final;
}



//Inverse topological sorting
//维护一个出度数组
vector<int> Inverse_topo(Matrix_DirectedGraph_Weighted &x)
{
    int n=x.getsize();
    bool has_cyle=true;
    stack<int> sup;
    vector<int> final;
    vector<int> out=x.get_outdegree();

    //遍历寻找出度为0的结点开始
    for (int i = 0; i < n; i++)
    {
        if (out[i]==0)
        {
            has_cyle=false;
            sup.push(i);
        }
        
    }
    //有环，退出
    if (has_cyle)
    {
        cout<<"Inverse topa: has cycle\n";
        return vector<int>();
    }
    

    //start
    while (!sup.empty())
    {
        //head element
        int head=sup.top();
        sup.pop();
        final.push_back(head);

        //find neighbors
        for (int i = 0; i < n; i++)
        {
            //find outdegree
            if (x.getgraph()[i][head]!=0)
            {
                out[i]-=1;
                if (out[i]==0)
                {
                    sup.push(i);
                }
                
            }
            
        }

        
    }
    
//final check
        if (final.size()<n)
        {
            cout<<"final.size= "<<final.size()<<"\tn= "<<n<<endl;
            cout<<"inverse topo:has cycle at end\n";
            return vector<int>();
        }
        
        return final;
    
}



vector<int>  Inverse_topo_DFS_full(Matrix_DirectedGraph_Weighted &x)
{
    //0: haven't visited; 1: visiting; 2:visited
    vector<int> state(x.getsize(),0);
    vector<int> final;

    //define a global bool, to insure break down when find a cycle
    bool has_cycle=false;
    for (int i = 0; i < x.getsize(); i++)
    {
        if (state[i]==0)
        {
            // if(i==3){
            //     pri_vec(visited);
            // }
            Inverse_topo_DFS(x,i,final,state,has_cycle);
        }
        
    }
    
    //check if has cycle
    if (has_cycle)
    {
        cout<<"has cycle, return a empty vector.\n";
        return vector<int>();
    }
    
    
    return final;


}

void Inverse_topo_DFS(Matrix_DirectedGraph_Weighted &x,int curr,vector<int> &q,vector<int> &state,bool &has_cycle)
{
    //check if has cycle
    if (has_cycle)
    {
        return;
    }
    
    if (state[curr]==1)
    {
        cout<<"at curr= "<<curr<<", visit a node is being visiting. has cycle\n";
        has_cycle=true;
        return;
    }else{
        state[curr]=1;
    }
    
    
    
    //找到第一条出边，并进入下一个结点
    for (int i = 0; i < x.getsize(); i++)
    { 
        
        if (x.getgraph()[curr][i]!=0 && state[i]!=2)
        {
            Inverse_topo_DFS(x,i,q,state,has_cycle);
            if (has_cycle) return; // 一旦发现环，立刻停止
        }
        
    }
    

    
    //没有出边，说明递归到达最大深度，该返回了
    //返回时添加当前结点值
    state[curr]=2;
    q.push_back(curr);
    
    return;
}