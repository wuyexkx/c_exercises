#include <stdio.h>

// 1. 宏定义，定义一个表示一年多少秒的宏
//  解释：
//  #define  宏名(大写)  宏体(编译时计算好，分为字符常量和表达式常量)
//  考点：
//    1.宏名大写 
//    2.宏体保护() 
//    3.嵌入式中数的长度，L表示至少4字节long型，无符号
#define SECOND_OF_YEAR  (365*24*3600UL)

// 2. 数据声明， 变量名结合方式，先右后左
//  int a;
//  int *a;
//  int **a;
//  int a[10];
//  int *a[10];
//  int (*a)[10];
//  int (*a)(int, char);
//  int (*a[10])(int, char);

// 3. 修饰符
    //  3.1 static
    //      修饰局部变量，存放于静态数据段的全局数据空间中 的 局部可见变量，生存期很长
    //      修饰全局变量，本文件可见的全局变量，防重名
    //      修饰全局函数，本文件可见的全局函数，防重名
    //  3.2 const
    //      只读，建议性，不具备强制性 （绝不是常量，一般改不了，可以越界修改，但是C++就是常量）
    //  3.3 volatile
    //      防止C编译器优化，修饰表明该变量可能被第三方修改（寄存器，中断，多线程）

// 4. 位操作
    //  4.1 某位置一
    //      a |= (0x01 << n); 
            #define SET_BITn(x, n) (x |= (0x01 << n))
    //  4.3 某位清零
    //      a &= ~(0x01 << n);
            #define CLEAR_BITn(x, n) (x &= ~(0x01 << n))
    //  4.4 8位寄存器，低四位清零
    //      a &= 0xF0;
//  32bit嵌入式操作，a
    //  4.5 获取某个字节
    //      (a >> (8*(n))) & 0xFF; 
            #define GET_BYTEn(x, n) ((x >> (8*(n))) & 0xFF)   
    //  4.6 获取某一位
    //      (a >> n) & 0x01;            // 第一种方法
    //      (a & (0x01 << n) >> n);     // 第二种方法
    //      (a & (0x01 << n)) ? 1 : 0;  // 第三种方法
            #define GET_BITn(x, n) ((x >> n) & 0x01)
    //  4.7 清零某个字节
    //      a &= ~(0xFF << n);
            #define CLEAR_BYTEn(x, n) (x &= ~(0xFF << (8*(n))))
    //  4.8 判断某一位的值
    //      if(  a & (0x01 << n) == 0 )
    //  4.9 翻转某一位的值
    //      a ^= (0x01 << n);
            #define REVERSE_BITn(x, n) (x ^= (0x01 << n))
    //  4.10 判断连续某几位的值 (32位)
    //      (unsigned int)(a << (31-(n))) >> (31-(n)+(m)) 
         #define GET_BIT_M2N(x, m, n) ( (unsigned int)(x << (31-(n))) >> (31-(n)+(m)) )

// 5. 访问固定内存的内容
    //  设置一绝对地址为0x1234的整型变量的值为0x5678
    //      第一种方法
    //      int *p = 0x1234;
    //      *p = 0x5678; or p[0] = 0x5678;
    //      第二种方法
    //      *((int *)0x1234) = 0x5678;
    //  调用这个地址0x1234的函数，函数形式为int func(int, char)
    //      ((int (*)(int, char))0x1234)();


int main()
{
    int i=0x12345678;
    printf("--------------\n");
    printf("i = 0x%x, sizeof = %d\n", i, sizeof(i));
    printf("--------------\n");
    printf("byte = 0x%x\n", GET_BYTEn(i, 0));
    printf("byte = 0x%x\n", GET_BYTEn(i, 1));
    printf("byte = 0x%x\n", GET_BYTEn(i, 2));
    printf("byte = 0x%x\n", GET_BYTEn(i, 3));

    printf("--------------\n");
    printf("bit = 0x%x\n", GET_BITn(i, 0));
    printf("bit = 0x%x\n", GET_BITn(i, 1));
    printf("bit = 0x%x\n", GET_BITn(i, 2));
    printf("bit = 0x%x\n", GET_BITn(i, 3));
    
    printf("--------------\n");
    printf("clear = 0x%x\n", CLEAR_BYTEn(i, 0));
    printf("clear = 0x%x\n", CLEAR_BYTEn(i, 1));
    printf("clear = 0x%x\n", CLEAR_BYTEn(i, 2));
    printf("clear = 0x%x\n", CLEAR_BYTEn(i, 3));

    printf("--------------\n");
    i = 0x88; // 1000 1000
    printf("reverse = 0x%x\n", REVERSE_BITn(i, 3));
    printf("reverse = 0x%x\n", REVERSE_BITn(i, 3));

    printf("--------------\n");
    i = 0xFE; // 1111 1110
    printf("bit m~n = 0x%x\n", GET_BIT_M2N(i, 1, 3));

    return 0;
}