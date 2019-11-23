#include <stdio.h>

// 一共有32个关键字 之 数据类型关键字--int
//  编译器最优的处理大小： 系统一个周期所能接收的最大处理单位，int，数据总线最大处理能力
//   其大小由编译器决定 32bit--4B  16bit--2B 
//   300l 300L 无论编译器是什么，系统是什么，l型至少4个字节

// 进制：
    // int a = 010; // 8
    // int a = 0x10;// 16

// unsigned 
    // signed最高位永远表示符号    有符号一般表示参与运算的的 数字
    // unsigned                  无符号数一般表示为         数据

// float double
    // float 4字节 
    // double 8字节
    // 常量如 1.1 2.3 为double占用8字节
    // 1.1f 2.3f 表示float占用4字节

// void 一般用于占位，使用时再具体强制转换。只用在声明， void a; a++;错误

int main()
{
    int a = 0x10;
    printf("sizeof is: %lu\n", sizeof(a));
    printf("a = %d", a); 
    return 0;
}

