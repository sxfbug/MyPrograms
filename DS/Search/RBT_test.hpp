// RBT_test.hpp
#ifndef RBT_TEST_HPP
#define RBT_TEST_HPP

#include "headfile.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <random>
#include <algorithm>

using namespace std;

// 测试辅助函数声明
class RBT_Tester {
private:
    // 检查红黑树性质
    static bool checkRBTreeProperties(RBTLink root);
    static bool checkProperty1(RBTLink node);  // 节点非红即黑
    static bool checkProperty2(RBTLink root);  // 根节点为黑
    static bool checkProperty4(RBTLink node);  // 红节点的子节点必须为黑
    static bool checkProperty5(RBTLink root);  // 所有路径黑高相同
    
    // 获取黑高
    static int getBlackHeight(RBTLink node);
    
    // 打印树结构（可视化）
    static void printRBTreeHelper(RBTLink root, int space, bool showColor);
    static void printRBTree(RBTLink root, bool showColor = true);
    
    // 验证节点连接关系
    static bool checkParentLinks(RBTLink root, RBTLink parent);
    
public:
    // 运行所有测试
    static void runAllTests();
    
    // 单个测试用例
    static void testCase1();  // 简单插入
    static void testCase2();  // LL旋转
    static void testCase3();  // RR旋转
    static void testCase4();  // LR旋转
    static void testCase5();  // RL旋转
    static void testCase6();  // 颜色翻转
    static void testCase7();  // 混合情况
    static void testCase8();  // 根节点重新着色
    static void testCase9();  // 重复元素
    static void testCase10(); // 有序插入
    static void testCase11(); // 逆序插入
    static void testCase12(); // 随机测试
};

#endif // RBT_TEST_HPP