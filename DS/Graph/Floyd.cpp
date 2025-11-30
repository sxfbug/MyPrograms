#include"graph.hpp"

//不能传引用进来，因为传入的矩阵需要进行修改，改为第n轮迭代后的各节点最短路径
void floyd(Matrix_DirectedGraph_Weighted &x){
    vector<vector<int>> path(x.getsize(),vector<int>(x.getsize(),-1));
    vector<vector<int>> dist=x.getgraph();
    //floyd part
    for (int i = 0; i < x.getsize(); i++)
    {
        for (int j = 0; j < x.getsize(); j++)
        {
            for (int k = 0; k < x.getsize(); k++)
            {
                //如果j->k不存在边，或存在的边大于引进节点i之后的j->i->k的边，则更新
                if (dist[j][k]==0||(dist[j][k]>dist[j][i]+dist[i][k]))
                {
                    dist[j][k]=dist[j][i]+dist[i][k];
                    path[j][k]=i;

                }
                
            }
            
        }
        cout<<"第"<<i<<"轮迭代完成\n";
        
    }
    //ending
    cout<<"dist array: "<<endl;
    pri_vec(dist);
    cout<<"path array: "<<endl;
    pri_vec(path);

    
}