// 指针的两个要素
    // 1.大小 
    //      这个指针的大小在一个系统中是固定的,32或者64位,4字节或者8字节, 无论是什么类型
    // 2.怎么读取数据, 访问数组空间的最小权限
    //      int *p, char *p, 一次读取4字节数据, 依次读取1字节数据

    //  地址是否存在,存在的地址是否可读可写, 也许不合法

    // 逻辑操作
    //  == !=
    //      同类型才能比较 char *p和int *p不能比较,编译报错


// 指针和数组
//  指针变量本身可变, 而数组名不能被赋值
//  字符串拷贝
    // strcpy();  // 只针对str, 遇到0或'\0'直接返回,所以非常不建议用strcpy,存在严重的内存泄漏问题
    // strncpy(); // 只针对str, 遇到0或'\0'直接结束, 手动指定长度(一个字符大小就是Byte)
    // memcpy();  // 任意, dest, src n(Byte), 推荐使用,但注意拷贝的数据类型如int, 需要n*sizeof(int) 规范操作
    // for(i=0; i<len; ++i) // 实际的字符串拷贝函数远比这复杂,嵌入根CPU相关的汇编语言,效果会更好
    // {
    //     dest[i] = src[i];
    // }
// 字符空间str, char buf[10] 
//      ASCII码为字符空间, 给人看的,如"abc", 'a', 'b', char a[10], 一般用于存放ASCII码字符
// 非字符空间data, unsigned char buf[10]
//      非字符空间用于存放数据的, 如采集到的传感器数据 
// 与二维数组
//  int a[3]; int *a; 基本一样, 访问空间权限就是int(4)
//  int (*p)[3]; 定义一个数组指针p, 指向int a[3]类型的数组, 初始化应该这样: int (*p)[3] = &a;
//  int a[3][4]; 与 int **a; 不一样

#include <stdio.h>
#include <string.h>

int main()
{

    // ====================str 与 pointer======================
    //  数组大小必须在编译期就作为一个常数确定下来
    char *p1 = "abcdefg";
    int num = 1000;
    int *p2 = &num;
    printf("p1 = %p, p2 = %p\n", p1, p2); // p1 = 0x564c7ba3e134, p2 = 0x7ffe8b33b4e8
    p1++;
    p2++;
    printf("p1 = %p, p2 = %p\n", p1, p2); // p1 = 0x564c7ba3e135, p2 = 0x7ffe8b33b4ec
    char pc1[] = {'a','b','c'}; 
    char pc2[] = {"abc"};
    char pc3[] = "abc";
    printf("%lu\n", sizeof(pc1)); // 3
    printf("%lu\n", sizeof(pc2)); // 4 编译器将"xxx"内容看作str,默认后面加'\0'
    printf("%lu\n", sizeof(pc3)); // 4


    // =================== 拷贝数组, str int =======================
    printf("\n strcpy: ");
    char buf1[4] = {0x01, 0x00, 0x02, 0x03};
    char buf2[4];
    strcpy(buf2, buf1);
    for(int i=0; i<sizeof(buf2); ++i) printf("%d ", buf2[i]); //  strcpy: 1 0 0 0
    printf("\nstrncpy: ");
    strncpy(buf2, buf1, 4);
    for(int i=0; i<sizeof(buf2); ++i) printf("%d ", buf2[i]); // strncpy: 1 0 0 0
    printf("\n memcpy: ");
    memcpy(buf2, buf1, 4*sizeof(char));
    for(int i=0; i<sizeof(buf2)/sizeof(char); ++i) printf("%d ", buf2[i]); //  memcpy: 1 0 2 3
    
    printf("\n memcpy int: \n");
    int buf3[4] = {123, 0, 456, 789};
    int buf4[4];
    memcpy(buf4, buf3, 4);              // 注意copy的长度, 默认是Byte
    for(int i=0; i<sizeof(buf4)/sizeof(int); ++i) printf("%d ", buf4[i]); //  123 32600 0 0 
    printf("\n");
    memcpy(buf4, buf3, 4*sizeof(int));  // 注意copy的长度, 默认是Byte
    for(int i=0; i<sizeof(buf4)/sizeof(int); ++i) printf("%d ", buf4[i]); //  123 0 456 789

    // =========================== 指针与数组 ================================
    //  int a[3]; a是一段连续内存的标签, 不可变, ***a是首元素地址, &a是返回数组指针***
    // 一维
    //      一维数组的首地址 就是首个元素的地址, == &a[0]
    int     a1[3] = {1,2,3};                  // 定义并初始化指针a
    int      *p01 = a1;                       // 定义一个指针, 赋值为a1数组的首地址 
    int   *pa1[3] = {&a1[0], &a1[1], &a1[2]}; // 定义并初始化指针数组
    int (*ap1)[3] = &a1;                      // 定义并初始化数组指针ap1, &a和a有区别, a是首元素地址, &a是数组指针
    printf("\n\n1 dim: \n");
    for(int i=0; i<3; ++i) printf("%d ", a1[i]); printf("\n");
    for(int i=0; i<3; ++i) printf("%d ", p01[i]); printf("\n");
    for(int i=0; i<3; ++i) printf("%d ", *pa1[i]); printf("\n");
    for(int i=0; i<3; ++i) printf("%d ", (*ap1)[i]); printf("\n");
    //  二维
    //      二维数组的首元素是第1行数组, 所以二维数组的首地址是***a是首元素地址, &a是返回数组指针***
    int a2[4][3] = {{0, 1, 2},  // 定义一个二维数组并初始化, 一行3个元素, 共4行
                    {4, 5, 6},
                    {7, 8, 9},
                    {0, 5, 8}};                            
    int **p02 = a2;             // 定义一个二级指针, 赋的值为a2首地址, [warning: initialization from incompatible pointer type]
                                //  a2的值是大小为3*sizeof(int)的连续空间的标签
                                //  而p02所指空间大小为系统pointer大小(p02保存的是一个int指针类型而已)
    int *pa2[4][3];             // 定义一个二维数组, 保存的是int*类型
    int (*ap2)[3] = a2;         // 定义一个数组指针, 赋值为a2的首地址, 就是第一行数组的标签
    int (*ap3)[4][3] = &a2;     // 定义一个数组指针, 赋值为a2这个二维数组的指针, 不加&会有上面一样的警告
    printf("2 dim: \n");
    for(int i=0; i<3; ++i) printf("%d ", (*ap2)[i]); printf("\n");
    ap2++;  // 指向下一行. 将这个数组指针移动一个单位, 这个单位长度就是所指数组的大小, 所指的是a2的某一行
    for(int i=0; i<3; ++i) printf("%d ", (*ap2)[i]); printf("\n");
    printf("int (*ap3)[4][3]: \n");
    for(int i=0; i<4; ++i)
    {
        for(int j=0; j<3; ++j)
            printf("%d ", (*ap3)[i][j]);
        printf("\n");
    }
    
    int aa[4][3] = {1,2,3};
    printf("\n prev: %p\n", aa);            //  prev: 0x7ffe0a2892f0 
    printf(" prev: %p\n", &aa);             //  prev: 0x7ffe0a2892f0 
    printf("after: %p\n", aa + 1);          // after: 0x7ffe0a2892fc 比prev增加12
    printf("after: %p\n", &aa + 1);         // after: 0x7ffe0a289320 比prev增加48

    // ======================= 一道题 =======================
    int a3[3] = {1, 2, 3};
    int *p3 = (int*)(&a3+1);
    printf("\n%d, %d\n",*(a3+1),*(p3-1));   // 2, 3 

    // 如何保存数组的首地址
    int b1[3];
    int b2[4][3];
    int b3[2][4][3];
    // 保存b1的首地址
    int *pp1 = b1;
    // 保存b2的首地址
    int (*pp2)[3] = b2;
    // 保存b3的首地址
    int (*pp3)[4][3] = b3;

    return 0;
}
