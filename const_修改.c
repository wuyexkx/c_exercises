#include <stdio.h>

// 内存地址上大下小，存储变量时是从上到下，
// 可以用指针通过这个顺序间接去改变const的值
// ----------   high
// |        |   a
// |        |   b
// |        |
// |        |
// |        |
// |        |
// |        |
// ----------   low

// const在C语言中，告诉编译器编译过程中不能变，但在运行中就不保证，比如可以越界修改

int main()
{
    const int a = 0x12345678; // a存放在高位地址
    
    int b = 0x11223344;       // b存放在相邻低位地址
    
    int *p = &b;              // 得到b的地址 

    printf("1. The a is: %x\n", a);
    // p += 1;              
    // *p = 0x100;
    p[1] = 0x100;             // 指针向上生长1，找到了a，并修改了a，跟上面方法一样

    printf("2. The a is: %x\n", a);

    return 0;
}

