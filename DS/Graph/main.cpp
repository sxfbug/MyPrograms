
#include"graph.hpp"

int main(){

    // Matrix_DirectedGraph_Weighted x(9);
    // x.AddEdge(1,2,10);
    // x.AddEdge(1,3,5);
    // x.AddEdge(2,3,3);
    // x.AddEdge(3,2,4);
    // x.AddEdge(3,4,4);
    // x.AddEdge(2,5,5);
    //dijk(x,1);

    // Matrix_DirectedGraph_Weighted y(6);
    // y.AddEdge(1,2,17);
    // y.AddEdge(1,3,3);
    // y.AddEdge(3,2,4);
    // y.AddEdge(2,3,9);
    // y.AddEdge(2,4,8);
    // y.AddEdge(3,5,2);
    // y.AddEdge(3,4,10);
    // y.AddEdge(5,4,5);
    //dijk(y,1);

    Matrix_DirectedGraph_Weighted z(7);
    z.AddEdge(0,1);
    z.AddEdge(1,6);
    z.AddEdge(1,2);
    z.AddEdge(3,4);
    z.AddEdge(4,5);
    z.AddEdge(4,2);
    vector<int> result=Topo(z);
    vector<int> result2=Inverse_topo(z);
    vector<int> result3=Inverse_topo_DFS_full(z);
    // pri_vec(result);    
    // pri_vec(result2);
    // pri_vec(result3);
    
    Matrix_DirectedGraph_Weighted a(4);
    a.AddEdge(0,1);
    a.AddEdge(1,2);
    a.AddEdge(2,3);
    a.AddEdge(3,1);
    // vector<int> r4=Topo(a);
    // Inverse_topo(a);
    // Inverse_topo_DFS_full(a);

    Matrix_DirectedGraph_Weighted ex(6);
    ex.AddEdge(0,1,3);
    ex.AddEdge(0,2,2);
    ex.AddEdge(1,3,2);
    ex.AddEdge(2,3,4);
    ex.AddEdge(1,4,3);
    ex.AddEdge(4,5,1);
    ex.AddEdge(3,5,2);
    ex.AddEdge(2,5,3);
    cri_path(ex);

    Matrix_DirectedGraph_Weighted test(6);
test.AddEdge(0, 1, 3);
test.AddEdge(0, 2, 2);
test.AddEdge(1, 3, 4);
test.AddEdge(2, 3, 5);
test.AddEdge(3, 4, 2);
test.AddEdge(3, 5, 3);
test.AddEdge(4, 5, 1);

vector<int> result_test = cri_path(test);

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