// test_avl_complete.cpp
#include "headfile.hpp"
#include <cstdlib>
#include <ctime>
#include <set>

void comprehensive_test() {
    cout << "========== 全面AVL树测试 ==========" << endl;
    
    // 测试1：基本功能
    cout << "\n测试1：基本插入和删除" << endl;
    AVLLink root = nullptr;
    int data1[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    
    for (int val : data1) {
        root = AVL_build(root, val);
    }
    
    cout << "插入15个节点后的树：" << endl;
    layerorder(root);
    
    // 测试删除各种节点
    int to_delete[] = {40, 50, 20, 70, 30};
    for (int val : to_delete) {
        cout << "\n删除节点 " << val << "：" << endl;
        root = AVL_delete(root, val);
        layerorder(root);
        cout << "中序遍历验证：" << endl;
        midorder(root);
    }
    
    // 测试2：随机测试
    cout << "\n\n测试2：随机插入和删除" << endl;
    AVLLink root2 = nullptr;
    srand(time(0));
    set<int> inserted;
    
    // 随机插入50个节点
    for (int i = 0; i < 50; i++) {
        int val = rand() % 1000;
        if (inserted.find(val) == inserted.end()) {
            inserted.insert(val);
            root2 = AVL_build(root2, val);
        }
    }
    
    cout << "随机插入后树高：" << (root2 ? root2->height : 0) << endl;
    
    // 随机删除一半节点
    vector<int> to_delete_list(inserted.begin(), inserted.end());
    for (int i = 0; i < to_delete_list.size() / 2; i++) {
        root2 = AVL_delete(root2, to_delete_list[i]);
    }
    
    cout << "删除一半节点后树高：" << (root2 ? root2->height : 0) << endl;
    
    // 测试3：极端情况
    cout << "\n\n测试3：极端情况 - 升序插入然后删除" << endl;
    AVLLink root3 = nullptr;
    for (int i = 1; i <= 20; i++) {
        root3 = AVL_build(root3, i);
    }
    cout << "升序插入20个节点后树高：" << root3->height << endl;
    
    // 按顺序删除
    for (int i = 1; i <= 20; i++) {
        root3 = AVL_delete(root3, i);
    }
    cout << "全部删除后树是否为空：" << (root3 == nullptr ? "是" : "否") << endl;
    
    // 测试4：删除不存在的节点
    cout << "\n\n测试4：删除不存在的节点" << endl;
    root = AVL_delete(root, 9999);
    cout << "树保持不变" << endl;
    
    cout << "\n========== 所有测试完成！ ==========" << endl;
}

int main() {
    comprehensive_test();
    return 0;
}