#!/bin/bash
echo "编译中..."
g++ -std=c++11 -g -O0 -Wall -Wextra -o main main.cpp bfs.cpp dfs.cpp support_function.cpp Dijkstra.cpp

if [ $? -eq 0 ]; then
    echo "编译成功！"
    echo "运行程序..."
    echo "========================"
    ./main
else
    echo "编译失败！"
fi