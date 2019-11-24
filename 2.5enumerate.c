#include <stdio.h>

// enum 并不强大，只是语义限制符，不是强制符号
// enum打包一堆整型常量，而struct是打包一堆变量。
// 其用法跟 #define F 1差不多，使用enum的原因是enum是一个集合的概念，方便人交流的打包常量集合

// 常数集合的名字叫做mye, 有没有无所谓
// 默认从0开始一次递增，可以自己指定如F=100
enum mye{F, S, T};

// 用一个枚举类型去定义一个枚举变量，但是这个变量只占4字节，只能取整数，并且编译器并不一定限制取值一定要是其成员
enum mye mye1;

int main()
{
    mye1 = 500; // 并不一定不可以，只是一种语义限制符。但是尽量不要这样写
    printf("sizeof: %lu, mye1 = %d\n", sizeof(mye1), mye1);
    return 0;
}
