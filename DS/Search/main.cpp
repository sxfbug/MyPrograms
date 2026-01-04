#include"headfile.hpp"

int main(){
    vector<int> x={1,3,4,10,12,16};//最搞笑的是，直接把顺序数组拿来构建bst,会使得bst退化为链表
    vector<int> z={3,4,2,7,9,8,1,17,14,25,20};
    vector<int> test={30, 20, 40, 10, 25, 35, 50, 5, 15, 28, 45};
    vector<int> xx={5,10,15};
    int y;
    
    BSTLink a=nullptr;
    AVLLink avl=nullptr;
    for (int i : test)
    {
        //a=BST_build(a,i);
        avl=AVL_build(avl,i);
        cout<<"after insert: "<<i<<endl;
        
    }
    layerorder(avl);
    cout<<"in-order traversal: "<<endl;
    midorder(avl);
    cout<<"pre order: "<<endl;
    preorder(avl);
    
    while (cin>>y)
    {
        AVLLink pre=nullptr;
        AVL_delete(avl,y);
        layerorder(avl);
        // if (re)
        // {
        //     cout<<"re.data= "<<re->data<<endl;
        //     AVLLink ino=spe_inorder(re->rchild,pre);

        //     if(!ino){
        //         cout<<"not inorder."<<endl;
        //     }else{
        //         cout<<"re.中序后继= "<<ino->data<<endl;
        //     }
        // }else if(!re){
        //     cout<<"not founded."<<endl;
        // }
        
        
        
        
    }
    

}