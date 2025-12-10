#include"headfile.hpp"

int main(){
    vector<int> x={1,3,4,10,12,16};//最搞笑的是，直接把顺序数组拿来构建bst,会使得bst退化为链表
    vector<int> z={3,4,2,7,9,8,1,17,14,25,20};
    int y;
    // while (cin>>y)
    // {
    //     cout<<"Seq: "<<Seq(x,y)<<endl;
    //     cout<<"Bin: "<<Bin(x,y)<<endl;
    // }
    BSTLink a=nullptr;
    AVLLink avl=nullptr;
    for (int i : z)
    {
        //a=BST_build(a,i);
        avl=AVL_build(avl,i);
        cout<<"after insert: "<<i<<endl;
        layerorder(avl);
    }
    
    
    // while (cin>>y)
    // {
    //     BST_delete(a,y);
    //     layerorder(a);
    // }
    

}