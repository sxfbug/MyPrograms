#include"graph.hpp"

using namespace std;






//完整的普通bfs，邻接矩阵
void BFS_full(Matrix_UndirectedGraph &x){
    vector<bool> flag(x.getsize(),false);
    for(int i=0;i<x.getsize();i++){

        if(flag[i]==false){
        BFS_single(x,i,flag);
        }
        
    }
     
     
}


//这个函数只能访问单联通分量
void BFS_single(Matrix_UndirectedGraph &x,int start,vector<bool> &flag){
    
    queue<int> q;

    //把第一个放入
    q.push(start);
    flag[start]=true;
    cout<<"visited"<<start<<endl;
    while(!q.empty()){
        //先返回队头元素，再pop,才能保存
        int temp=q.front();
        q.pop();
        for(int i=0;i<x.getsize();i++){
            if(x.getgraph()[temp][i]==1 && flag[i]==false){
                q.push(i);
                flag[i]=true;
                cout<<"visited:"<<i<<endl;
            }
        }

    }

}


//这个还有问题
void BFS_List(List_Graph &x){
    //记录是否访问的数组
    vector<bool>flag(x.get_size(),false);


    //辅助队列和指针
    queue<int>sup;
    
    
    for (int i = 0; i < x.get_size(); i++)
    {
        if (flag[i]==false)
        {
            cout<<"连通分量： "<<i<<endl;
            int start=i;
            sup.push(start);
            
            //当前连通分量，也就是队列非空的时候
            while (!sup.empty())
            {
                
                
                //访问，pop队头元素
                int out=sup.front();
                sup.pop();
                flag[out]=true;

                if (x.get_graph()[out]==nullptr)
                {
                    cout<<"顶点 "<< out <<" 没有出边"<<endl;
                    continue;
                }else{
                    x.visit(x.get_graph()[out]);
                    }
                
                
                //寻找队头元素的相邻节点,并添加到队列中
                List_Graph::Linklist next=x.get_graph()[out]->pointer;
                //对于当前链表，访问整个链表
                while (next!=nullptr)
                {
                    out=next->data;
                    if (flag[out]==false)
                    {
                        sup.push(out);
                        flag[out]=true;
                        if (x.get_graph()[out]==nullptr)
                        {
                            cout<<"顶点 "<< out <<" 没有出边"<<endl;
                        }else{
                            x.visit(x.get_graph()[out]);
                        }
                        
                    }
                    next=next->pointer;                   
                }
    }
    

    
    

    

}            
        }
        
    }
    




//bfs求最短路径
//一个路径数组只能服务于一个连通分量

void bfs_path_full(Matrix_UndirectedGraph &x){
    //访问标记数组
    vector<bool> flag(x.getsize(),false);
    for (int i = 0; i < x.getsize(); i++)
    {
      if (flag[i]==false)
      {
        //路径数组和前驱数组
        vector<int> path(x.getsize(),0);
        vector<int> prev(x.getsize(),-1);
        bfs_path(x,flag,path,prev,i);
        cout<<"联通分量： "<<i<<endl;

        cout<<"路径数组： "<<endl;
        pri_vec(path);

        cout<<"前驱数组： "<<endl;
        pri_vec(prev);

      }
        
    }



}

void bfs_path(Matrix_UndirectedGraph &x,vector<bool> &flag, vector<int> &path
,vector<int> &prev,int start)
{
    //记录直接前驱
    
    queue<int> sup;
    //入队
    sup.push(start);
    //对队列进行处理
    path[start]=0;
    flag[start]=true;
    prev[start]=-2;
    
    //当队列非空时
    while (!sup.empty())
    {
        //返回队头元素并pop，对队头元素进行访问
        //此时的element相当于后面入队元素的直接前驱了
        int element=sup.front();
        sup.pop();




        //寻找队头元素的相邻元素
        for (int i = 0; i < x.getsize(); i++)
        {
            if (x.getgraph()[element][i]==1 && flag[i]==false)
            {
                sup.push(i);
                flag[i]=true;  
                prev[i]=element;
                path[i]=path[element]+1;
            }            
        }
        

        


        //
        /* code */
    }
    
}







