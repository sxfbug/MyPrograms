#include"graph.hpp"

//vector<bool> flag(x.getsize(),false);

void DFS_matrix_full(Matrix_UndirectedGraph &x,vector<bool> &flag){
    for (int i = 0; i < x.getsize(); i++)
    {
        if (flag[i]==false)
        {
            DFS_matrix(x,i,flag);
        }
        
    }
}


//单联通分量
void DFS_matrix(Matrix_UndirectedGraph &x,int start,vector<bool> &flag){
    
    //访问初始元素
    x.visit(start);
    flag[start]=true;

    //访问 未被访问过的 start的邻接结点
    for (int i = 0; i < x.getsize(); i++)
    {
        if (x.getgraph()[start][i]==1&&flag[i]==false)
        {
            DFS_matrix(x,i,flag);
        }
        
    }
    
    
    
}

//显式维护一个栈，将第一个相邻且未访问过的元素压栈
void DFS_lteration(Matrix_UndirectedGraph &x,int start,stack<int> sup,vector<bool> &flag){
    //push init element
    //在压入的时候访问
    sup.push(start);
    x.visit(start);
    flag[start]=true;

    for (int i = 0; i < x.getsize(); i++)
    {
        //if not visited yet
        //压入第一个相邻的元素，之后要访问这个元素
        if(x.getgraph()[start][i]==1 && flag[i]==false){
            sup.push(i);
        }
    }

    
}



