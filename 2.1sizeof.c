#include <stdio.h>

// 一共有32个关键字
//  关键字的作用其实就是去约束变量在内存中的空间
// 1. sizeof
//  编译器给我们查看变量内存空间容量的工具,定义的数据大小跟编译器有关,只是常说char1, int4, long4/8, short2
// 2. return
int main()
{
    int a = 0;
    printf("sizeof is: %lu\n", sizeof(a)); // %lu无符号长整型
    return 0;
}

