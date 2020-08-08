#include <stdio.h>

// 关于宏的多个知识点
// 0 调式使用宏打印
// 1 逗号表达式实现首个默认参数 
// 2 结构体初始化
// 3 多默认参数
// 4 多默认参数

#define DEBUG 

#ifdef DEBUG
#define DEBUG_PRINT(STRING, args...) printf(STRING, ##args) // __VA_ARGS__ 宏用来表示可变参数的内容，就是将左边宏中 … 的内容原样抄写在右边__VA_ARGS__ 所在的位置
// #define DEBUG_PRINT(STRING, ...) printf(STRING, ##__VA_ARGS__) 
#elif
#define DEBUG_PRINT(args...)  // 可变参数别称args 自定义aaa...也行
#endif


// 1 首个默认参数------------------------------------------------------------
// 一个默认参数 巧借逗号表达式
// 注意在使用默认值时后面的","需要通过##吞掉
#define FUNC(...) func((8, ##__VA_ARGS__))  // 注意内部还有个括号才能实现逗号表达式 

int func(int i)
{
    printf("%d\n", i);
}
// ------------------------------------------------------------------------



// 2 结构体初始化----------------------------------------------
typedef struct test {
    int a;
    char b;
    int (*p)(int, char);
} A;
// 用于定义struct数组的宏，初始化方式用...代替
#define def_test_arr(__name, ...) \
        A __name[] = {__VA_ARGS__};
// 用于初始化某个struct test的字段的宏
#define init_test(__a, __b, ...)                            \
    {                                                       \
        .a = (__a),                                         \
        .b = (__b),                                         \
        .p = ((int (*)(int, char))0x5678, ##__VA_ARGS__),   \
    }
// ----------------------------------------------------------



// 3 多默认参数 -----------------------------
// 运用三目运算符来选择参数，有则第一个，无则第二个
// #name[0] 先字符化 name，然后取出字符串的第0个元素，如果有则第一个参数，否则defval
// name + 0 如果name为空则三目表达式语法错误
#define DEFARG(name, defval) (#name[0] ? (name + 0) : (defval))
#define add(arg0, arg1, arg2) _add(DEFARG(arg0, 1), DEFARG(arg1, 2), DEFARG(arg2, 3))
void _add(int a, int b, int c)
{
    printf("%d  %d  %d\n", a, b, c);
}
// ----------------------------------------



// 4 do while(0) --------------------------------
// 为什么要在宏里用这个东西？
// #define AAA() printf("111\n"); printf("222\n");
// if (2 < 1) AAA();    // 下面两种情况被解析成 一部分满足条件
// if (2 < 1) 
//     AAA();
// if (2 < 1) {         // 我们认为会这样
//     AAA();
// }

// #define AAA() { printf("111\n"); printf("222\n"); }
// AAA();      // 通常调用时末尾加上";"，展开后 {}; // 现在的编译器会自动检测自动忽略分号，不会报错，但是我们还是希望能跑在老的编译器上。

// 下面两种写法可以避免多一个";"问题，也能解决可能出现的逻辑问题
// #define AAA()               \
//     do {                    \
//         printf("111\n");    \
//         printf("222\n");    \
//     } while (0)
#define AAA() do { printf("111\n"); printf("222\n"); } while (0)
// ----------------------------------------------


int main()
{
    // ========================================
    DEBUG_PRINT("-- ===== --\n");
    DEBUG_PRINT("%d  %s  %c\n", 8, "hello", 'A');
    // DEBUG_PRINT();
        // -- ===== --
        // 8  hello  A



    // 1 首个默认参数 ========================================
    FUNC();
    FUNC(88);
        // 8
        // 88



    // 2 结构体初始化 ========================================
    // 定义结构体数组 并初始化 默认初始化
    def_test_arr(test2,
        init_test(1, 2, (int (*)(int, char))0x1234),
        init_test(3, 4),
        init_test(5, 6),
    );
    // 定义一个结构体变量，并初始化
    A test3 = init_test(0, 0, (int (*)(int, char))0x4321);
    // 打印
    printf("%d  %d  %p\n", test2[0].a, test2[0].b, test2[0].p);
    printf("%d  %d  %p\n", test2[1].a, test2[1].b, test2[1].p);
    printf("%d  %d  %p\n", test2[2].a, test2[2].b, test2[2].p);
    printf("%d  %d  %p\n", test3.a, test3.b, test3.p);
        // 1  2  0x1234
        // 3  4  0x5678
        // 5  6  0x5678
        // 0  0  0x4321



    // 3 多默认参数 ===========================================
    // func() 和 func( )参数解析都是 ""
    add(,,);
    add(2,,);
    add(,3,);
    add(,,4);
    add(4,5,6);
        // 1  2  3
        // 2  2  3
        // 1  3  3
        // 1  2  4
        // 4  5  6



    // 4 do while(0) ========================================
    AAA();
        // 111
        // 222


    return 0;
}
