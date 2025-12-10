#ifndef HF
#define HF
#include<iostream>
#include<vector>
#include<queue>

using namespace std;


//前向声明
struct BSTNode;
typedef BSTNode* BSTLink;
//typedef of structs

typedef struct BSTNode{
    int data;
    BSTLink lchild;
    BSTLink rchild;
};

struct AVLNode;
typedef AVLNode* AVLLink;

struct AVLNode{
    int data;
    AVLLink lchild;
    AVLLink rchild;
    int balanced;
    int height;//树高
};



//函数声明
//sequence.cpp
int Seq(vector<int> &x,int y);
//Binary.cpp
int Bin(vector<int> &x,int y);
//BST.cpp
BSTLink BST_build(BSTLink &root,int data);
void BST_search(BSTLink &x,int t,BSTLink &prev,BSTLink &now);
void BST_delete(BSTLink &x,int t);
//AVL.cpp
AVLLink AVL_build(AVLLink &x,int t);
AVLLink AVL_update(AVLLink &x);



//support function
void preorder(BSTLink &x);
void midorder(BSTLink &x);
void lastorder(BSTLink &x);
void layerorder(BSTLink &x);

void preorder(AVLLink &x);
void midorder(AVLLink &x);
void lastorder(AVLLink &x);
void layerorder(AVLLink &x);

BSTLink spe_midorder(BSTLink &x);
BSTLink spe_backorder(BSTLink &x,BSTLink &pre);


void pri_vec(vector<bool> &a);

#endif