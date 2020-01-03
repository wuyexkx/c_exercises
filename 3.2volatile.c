#include <stdio.h>

// 告知编译器编译方法的关键字，不优化编译
// 每次都要去实际地址读取数据，不要假惺惺的优化
// volatile变量可能被软件以外的东西改变

int main()
{
    volatile int a=9;
    while(a == 9); // 理论上a永远等于9，编译器可能优化成不去实际内存读数据如果这个变量根硬件直接相关那么可能被该变

}