给脚本开放权限：
chmod +x build.sh
build.sh是脚本的完整文件名

git推送更新到github
git add .
git commit -m"注释"
git push


# 项目：表达式树

### 更新日志
version 1： 加法、乘法，无括号
version 2： 加入减法、除法(除法运算结果为double)
ver3:处理括号,单层括号


### 使用方法
在提示字符串打印之后，输入想要计算的表达式，按下回车即可计算
Linux输入ctrl+d，（文件流末尾EOF），程序即可结束运行



### 括号
括号意味着什么？优先级增加一级
表达式的一个子树，内部的内容相当于被括号括起来了
所以，一对括号内部->一棵子树？