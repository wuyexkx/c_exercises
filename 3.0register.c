#include <stdio.h>

// 类型修饰符的作用：
// 对内存资源存放位置的限定

// 数据类型用于限定内存大小，类型修饰符用于限定内存资源存放的位置

// register 限定变量定义在寄存器上的修饰符
//  定义一些快速访问的变量在寄存器上，但是编译器只是尽量使CPU寄存器去存放变量
//  &对register变量不起作用

int main()
{
    register int a=0x10;

    printf("a = %d\n", a);
    return 0;
}