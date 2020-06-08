#if 0
filename="$0"
name="${filename%.*}"
CC="gcc"
$CC -o $name $filename
$name $@
rm $name
exit
#endif

#include<stdio.h>

// 位域 C语言struct 和 union特有的bit操作
struct bitField1 {
    unsigned char data1 : 7;        
    unsigned char data2 : 1;
};
struct bitField2 {
    unsigned char data1 : 3;        
    unsigned char data2 : 5;
};

// 内存对齐 内存是按字节存放，但是取指令是按4 8等连续字节，提高效率，避免多次取值合并造成的效率问题
// win下gcc中默认#pragma pack(8) linux也是，可以通过预编译命令#pragma pack(n)，n = 1,2,4,8,16来改变这一系数。
#pragma pack(8) // alignment must be a small power of two

// 有效对齐值：是给定值#pragma pack(n)和结构体中最长数据类型长度中较小的那个。有效对齐值也叫对齐单位。
    // 有效对齐值 = min(n, max size member of struct)

// struct的大小需要满足下面两个条件 一个约束成员，一个约束总大小：    
// (1) 结构体第一个成员的偏移量（offset）为0，offset = 整数倍的min(有效对齐值, size of this member)
    // 以后每个成员相对于结构体首地址的 offset 都是该成员大小与有效对齐值中较小那个的整数倍
    // 如有需要编译器会在成员之间加上填充字节。
// (2) 结构体的总大小为 有效对齐值 的整数倍，如有需要编译器会在最末一个成员之后加上填充字节。
struct A { // 12
    char a;     //                             offset=0  占用 0           填充[1]     
    short b;    // 成员大小2 offset必须为2的整数倍 offset=2  占用 2 3         无填充      
    char c;     // 成员大小1 offset必须为1的整数倍 offset=4  占用 4           填充[5 6 7] 
    int d;      // 成员大小4 offset必须为4的整数倍 offset=8  占用 8 9 10 11   无填充      
    // double cc;  // 成员大小8 offset必须为4的整数倍 offset=12 占用 12...19     无填充 // struct大小20Byte
};
struct B { // 8
    short a;    //                             offset=0  占用0 1          无填充
    char b;     // 成员大小1 offset必须为1的整数倍 offset=2  占用2            无填充
    char c;     // 成员大小1 offset必须为1的整数倍 offset=3  占用3            无填充
    int d;      // 成员大小4 offset必须为4的整数倍 offset=4  占用4 5 6 7      无填充
};
#pragma pack()


int main()
{
    struct bitField1 b1;
    struct bitField2 b2;
    printf("%lu %lu\n", sizeof(b1), sizeof(b2)); // 1 1

    struct A a;
    struct B b;    
    printf("%lu %lu\n", sizeof(a), sizeof(b)); // 12 8

    return 0;
}