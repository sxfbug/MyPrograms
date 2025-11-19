#ifndef GRAPH
#define GRAPH

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//无向图Undirected graph 邻接矩阵
class Matrix_UndirectedGraph{
    private:
    //矩阵和元素数量
    vector<vector<int>> graph;
    int size;
    
    public:
    //构造函数
    Matrix_UndirectedGraph(int x):graph(x,vector<int>(x,0)),size(x){}
    //获取元素数量
    int getsize(){
        return size;
    }
    //获取邻接矩阵
    vector<vector<int>>& getgraph(){
        return graph;
    }
    //添加从x到y的边
    void AddEdge(int x,int y){
        graph[x][y]=1;
        graph[y][x]=1;
    }
    //访问结点
    void visit(int x){
        cout<<"结点:"<<x<<"\t";
    }
};


//带权有向图Directed graph 邻接矩阵
class Matrix_DirectedGraph_Weighted{
    private:
    int size;
    vector<vector<int>> graph;

    public:
    //构造函数
    Matrix_DirectedGraph_Weighted(int x):size(x),graph(x,vector<int>(x,0)){};
    //获取元素数量
    int getsize(){
        return size;
    }
    //获取邻接矩阵
    vector<vector<int>>& getgraph(){
        return graph;
    }
    //添加从x到y的带权边
    void AddEdge(int x,int y,int weight){
        graph[x][y]=weight;
    }

    //访问结点
    void visit(int x){
        cout<<"结点:"<<x<<"\t";
    }   

     
    
};

//有向图Directed graph 邻接表
class List_Graph
{
private:
    int size;
public:
    //节点结构体
    typedef struct Node{
        int data;
        Node* pointer;
        Node(int x):data(x),pointer(nullptr){}
    }*Linklist;

    //顶点数组
    vector<Node*> graph;

    //class init
    List_Graph(int x):size(x),graph(x,nullptr){
        // for (int i = 0; i < size; i++)
        // {
        //     Linklist newone=new Node(i);
        //     graph[i]=newone;
        // }
        
    }
    
    //获取大小
    int get_size(){
        return size;
    }
    //获取顶点数组
    vector<List_Graph::Node*> get_graph(){
        return graph;
    }

    //访问节点
    void visit(Node* x){
        if(x==nullptr){
            cout<<"null"<<endl;
        }else{
            cout<<"data: "<<x->data<<endl;
        }
    }

    //添加边,添加一条从x到y的边，头插法，因为尾插法还要维护一个指针
    void AddEdge(int x,int y){
        Node* newnode=new Node(y);
        newnode->pointer=graph[x];
        graph[x]=newnode;
    }


    //遍历打印整个图
    void print_graph(){
        Linklist curr,next;
        for (int i = 0; i < size; i++)
        {
            curr=graph[i];
            cout<<"graph element: "<<i<<endl;
            while (curr!=nullptr)
            {
                visit(curr);
                curr=curr->pointer;
            }
            
        }
        
    }

    //删除节点y,需要先找到y,再删除y
    void DeleteNode(int y){
        Node *current,*next;

        //删除y的出边，先找到y为起始的这个链表，再逐个释放内存，不然会导致内存泄漏
        //用数组模拟栈来辅助释放，先遍历找到链表末端，再从末端开始释放
        //不需要用数组，一个变量记录上个节点即可

        //添加了判空，为空直接跳过
        if (graph[y]==nullptr)
        {
            /* code */
        }else{
            current=graph[y];
            next=current->pointer;
            //遍历链表，从头删到尾，next保存下一个指针
            while(next!=nullptr)
            {
                delete current;
                current=next;
                next=current->pointer;
            }
            //删除最后一个元素，并把graph对应位置置为nptr
            delete current;
            graph[y]=nullptr;
        }
        
        

        //寻找并删除y的入边
        //遍历graph vector中的每个元素
        for (int i = 0; i < size; i++)
        {
            
            //新增判空和跳过
            if (graph[i]==nullptr || i==y)
            {
                continue;
            }else{
                current=graph[i];
                next=current->pointer;
            }
            
            
            
            
            //从当前链表第二个开始找
            while (next!=nullptr)
            {
                //找到了，此时next是要删除的节点，current是父节点
                if (next->data==y)
                {
                    current->pointer=next->pointer;
                    delete next;
                    break;
                }
                //没找到，继续迭代指针
                current=next;
                next=current->pointer;
            }

            

            
        }
        
    }


    
};






//函数声明
//bfs
void BFS_full(Matrix_UndirectedGraph &x);
void BFS_single(Matrix_UndirectedGraph &x,int start,vector<bool>&flag);
//dfs
void DFS_matrix_full(Matrix_UndirectedGraph &x,vector<bool> &flag);
void DFS_matrix(Matrix_UndirectedGraph &x,int start,vector<bool> &flag);
//bfs shortest path
void bfs_path(Matrix_UndirectedGraph &x,vector<bool> &flag, vector<int> &path
,vector<int> &prev,int start);
void bfs_path_full(Matrix_UndirectedGraph &x);
//dijkstra
void dijk(Matrix_DirectedGraph_Weighted &x,int start);
int find_min(vector<int> &x,vector<bool> &flag);

//辅助函数声明
void pri_vec(vector<bool> &x);
void pri_vec(vector<int> &x);
void pri_vec(vector<vector<int>> &x);
#endif