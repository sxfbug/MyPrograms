// practice1.c - 理解进程创建
#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main() {
    printf("Before fork, PID: %d\n", getpid());
    
    pid_t pid = fork();
    if (pid == 0) {
        // 子进程
        printf("Child process, PID: %d\n", getpid());
    } else {
        // 父进程  
        printf("Parent process, child PID: %d\n", pid);
    }
    return 0;
}