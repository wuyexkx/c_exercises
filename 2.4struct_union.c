#include <stdio.h>

// 一共有32个关键字 之 数据类型关键字--struct
// 自定义数据类型
// c语言编译器默认定义的内存不符合实际资源的形式，需要自己定义

//  各元素之间的组合，但是是连续空间的。各变量顺序不同会导致总的结构体大小不同
//  各元素的空间是累加的关系，但是各空间是独立的（对应实际硬件）
// 共用体（联合体）的元素共用起始地址的一段内存，技巧性代码，修改一个值另一个可能改变


// 告诉编译器，我给这种内存的名字取名为mys，这段内存的形式是这样的。。
// 但是并不会分配空间，告诉编译器有这么种形式的内存空间叫做mys
// struct mys buff; 这样才算申请到内存
struct mys{
    unsigned int a;
    unsigned int b;
};

// 共用体，告诉编译器有种共用内存的名称为myu（这段内存的类型），
// union myu buff; 申请内存
union myu{
    int a;
    char b;
};


int main()
{
    struct mys mys1;
    printf("sizeof is: %lu\n", sizeof(mys1));

    union myu nyu1;
    
    return 0;
}
