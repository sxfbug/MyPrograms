#include"headfile.hpp"
#include"RBT_test.hpp"

int main() {
    cout << "红黑树测试程序" << endl;
    
    // 运行所有测试用例
    RBT_Tester::runAllTests();
    
    // 或者单独运行某个测试用例
    // RBT_Tester::testCase1();
    // RBT_Tester::testCase2();
    // ...
    
    return 0;
}
