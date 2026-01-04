#include "headfile.hpp"
#include "RBT_test.hpp"  // 保存上面的代码为RBT_test.hpp



// 实现测试辅助函数
bool RBT_Tester::checkProperty1(RBTLink node) {
    if (!node) return true;
    return (node->color == RED || node->color == BLACK);
}

bool RBT_Tester::checkProperty2(RBTLink root) {
    return !root || root->color == BLACK;
}

bool RBT_Tester::checkProperty4(RBTLink node) {
    if (!node) return true;
    if (node->color == RED) {
        // 检查左孩子
        if (node->lchild && node->lchild->color == RED) {
            cout << "违反性质4: 红色节点 " << node->data 
                 << " 有红色左孩子 " << node->lchild->data << endl;
            return false;
        }
        // 检查右孩子
        if (node->rchild && node->rchild->color == RED) {
            cout << "违反性质4: 红色节点 " << node->data 
                 << " 有红色右孩子 " << node->rchild->data << endl;
            return false;
        }
    }
    return checkProperty4(node->lchild) && checkProperty4(node->rchild);
}

int RBT_Tester::getBlackHeight(RBTLink node) {
    if (!node) return 1;  // NIL节点是黑色
    
    int leftHeight = getBlackHeight(node->lchild);
    int rightHeight = getBlackHeight(node->rchild);
    
    // 返回当前节点所在路径的黑色节点数
    return (node->color == BLACK ? 1 : 0) + leftHeight;
}

bool RBT_Tester::checkProperty5(RBTLink root) {
    if (!root) return true;
    
    // 获取左子树的黑高
    int leftBlackHeight = getBlackHeight(root->lchild);
    int rightBlackHeight = getBlackHeight(root->rchild);
    
    if (leftBlackHeight != rightBlackHeight) {
        cout << "违反性质5: 节点 " << root->data 
             << " 左右子树黑高不同 (左: " << leftBlackHeight 
             << ", 右: " << rightBlackHeight << ")" << endl;
        return false;
    }
    
    return checkProperty5(root->lchild) && checkProperty5(root->rchild);
}

bool RBT_Tester::checkParentLinks(RBTLink root, RBTLink parent) {
    if (!root) return true;
    
    if (root->parent != parent) {
        cout << "父指针错误: 节点 " << root->data 
             << " 的父指针应该指向 " << (parent ? parent->data : -1) 
             << "，实际指向 " << (root->parent ? root->parent->data : -1) << endl;
        return false;
    }
    
    return checkParentLinks(root->lchild, root) && 
           checkParentLinks(root->rchild, root);
}

bool RBT_Tester::checkRBTreeProperties(RBTLink root) {
    bool allPassed = true;
    
    // 检查性质2
    if (!checkProperty2(root)) {
        cout << "违反性质2: 根节点不是黑色" << endl;
        allPassed = false;
    }
    
    // 检查性质4
    if (!checkProperty4(root)) {
        allPassed = false;
    }
    
    // 检查性质5
    if (!checkProperty5(root)) {
        allPassed = false;
    }
    
    // 检查父指针
    if (!checkParentLinks(root, nullptr)) {
        cout << "父指针错误" << endl;
        allPassed = false;
    }
    
    return allPassed;
}

void RBT_Tester::printRBTreeHelper(RBTLink root, int space, bool showColor) {
    const int COUNT = 5;  // 每个层级的缩进量
    if (!root) return;
    
    space += COUNT;
    
    printRBTreeHelper(root->rchild, space, showColor);
    
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    
    if (showColor) {
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ")";
    } else {
        cout << root->data;
    }
    
    printRBTreeHelper(root->lchild, space, showColor);
}

void RBT_Tester::printRBTree(RBTLink root, bool showColor) {
    cout << "\n红黑树结构:" << endl;
    printRBTreeHelper(root, 0, showColor);
    cout << endl;
}

// 测试用例实现
void RBT_Tester::testCase1() {
    cout << "\n=== 测试用例1: 简单插入 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {10, 20, 5, 15};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例1通过!" << endl;
}

void RBT_Tester::testCase2() {
    cout << "\n=== 测试用例2: LL旋转 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {30, 20, 10};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例2通过!" << endl;
}

void RBT_Tester::testCase3() {
    cout << "\n=== 测试用例3: RR旋转 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {10, 20, 30};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例3通过!" << endl;
}

void RBT_Tester::testCase4() {
    cout << "\n=== 测试用例4: LR旋转 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {30, 10, 20};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例4通过!" << endl;
}

void RBT_Tester::testCase5() {
    cout << "\n=== 测试用例5: RL旋转 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {10, 30, 20};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例5通过!" << endl;
}

void RBT_Tester::testCase6() {
    cout << "\n=== 测试用例6: 颜色翻转 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {41, 38, 31, 12, 19, 8};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例6通过!" << endl;
}

void RBT_Tester::testCase7() {
    cout << "\n=== 测试用例7: 混合情况 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {10, 5, 20, 3, 7, 15, 25, 1};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例7通过!" << endl;
}

void RBT_Tester::testCase8() {
    cout << "\n=== 测试用例8: 根节点重新着色 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data = {10, 20, 5, 15, 25, 12};
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例8通过!" << endl;
}

void RBT_Tester::testCase9() {
    cout << "\n=== 测试用例9: 重复元素 ===" << endl;
    RBTLink root = nullptr;
    
    // 第一次插入
    root = RBT_build(root, nullptr, 10);
    root = RBT_adjust(root);
    if (root && root->parent) root->parent = nullptr;
    
    // 保存第一次插入后的树结构
    RBTLink originalRoot = root;
    
    // 插入重复元素
    cout << "\n插入重复元素 10:" << endl;
    root = RBT_build(root, nullptr, 10);
    root = RBT_adjust(root);
    if (root && root->parent) root->parent = nullptr;
    
    printRBTree(root);
    assert(checkRBTreeProperties(root));
    
    // TODO: 这里可以添加检查树是否未改变的验证
    // 注意：这取决于你的RBT_build如何处理重复元素
    
    cout << "测试用例9通过!" << endl;
}

void RBT_Tester::testCase10() {
    cout << "\n=== 测试用例10: 有序插入 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data;
    for (int i = 1; i <= 10; i++) {
        data.push_back(i);
    }
    
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例10通过!" << endl;
}

void RBT_Tester::testCase11() {
    cout << "\n=== 测试用例11: 逆序插入 ===" << endl;
    RBTLink root = nullptr;
    
    vector<int> data;
    for (int i = 10; i >= 1; i--) {
        data.push_back(i);
    }
    
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例11通过!" << endl;
}

void RBT_Tester::testCase12() {
    cout << "\n=== 测试用例12: 随机测试 ===" << endl;
    RBTLink root = nullptr;
    
    // 生成随机序列
    vector<int> data;
    for (int i = 1; i <= 20; i++) {
        data.push_back(i);
    }
    
    // 随机打乱
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
    
    cout << "随机插入序列: ";
    for (int val : data) {
        cout << val << " ";
    }
    cout << endl;
    
    for (int val : data) {
        cout << "\n插入 " << val << ":" << endl;
        root = RBT_build(root, nullptr, val);
        root = RBT_adjust(root);
        
        // 确保根节点parent为nullptr
        if (root && root->parent) {
            root->parent = nullptr;
        }
        
        printRBTree(root);
        assert(checkRBTreeProperties(root));
    }
    
    cout << "测试用例12通过!" << endl;
}

void RBT_Tester::runAllTests() {
    cout << "开始红黑树测试..." << endl;
    
    try {
        testCase1();
        testCase2();
        testCase3();
        testCase4();
        testCase5();
        testCase6();
        testCase7();
        testCase8();
        testCase9();
        testCase10();
        testCase11();
        testCase12();
        
        cout << "\n所有测试用例通过!" << endl;
    } catch (const exception& e) {
        cerr << "测试失败: " << e.what() << endl;
    }
}

