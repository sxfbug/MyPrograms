#include<iostream>
#include<vector>
#include<queue>
#include"graph.hpp"

int main(){

    Matrix_DirectedGraph_Weighted x(9);
    x.AddEdge(1,2,10);
    x.AddEdge(1,3,5);
    x.AddEdge(2,3,3);
    x.AddEdge(3,2,4);
    x.AddEdge(3,4,4);
    x.AddEdge(2,5,5);
    //dijk(x,1);

    Matrix_DirectedGraph_Weighted y(6);
    y.AddEdge(1,2,17);
    y.AddEdge(1,3,3);
    y.AddEdge(3,2,4);
    y.AddEdge(2,3,9);
    y.AddEdge(2,4,8);
    y.AddEdge(3,5,2);
    y.AddEdge(3,4,10);
    y.AddEdge(5,4,5);
    dijk(y,1);

    
    // Matrix_UndirectedGraph x(9);
    // x.AddEdge(1,2);
    // x.AddEdge(2,3);
    // x.AddEdge(0,3);
    // x.AddEdge(5,6);
    // x.AddEdge(5,8);
    // // BFS_full(x);
    // // vector<bool> f(9,false);
    // // DFS_matrix_full(x,f);
    // bfs_path_full(x);  


    
    // List_Graph a(10);
    // a.AddEdge(1,4);
    // a.AddEdge(4,7);
    // a.AddEdge(2,5);
    // a.AddEdge(2,6);
    // a.AddEdge(5,4);
    // a.AddEdge(4,8);
    // a.AddEdge(8,5);
    // a.print_graph();
    // cout<<endl;
    // BFS_List(a);


}