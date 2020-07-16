#include <iostream>
#include <cassert>
// #include <cstring>
#include "test.h"

// 返回值的目的是满足链式表达
// ====================================================================
// 按字节赋值，可以完成字符赋值 或 为 0 -1，其他不行 （0， 0xFF）
void* memset(void* src, int c, size_t n)
{
    assert(src != NULL);
    char* psrc = (char*)src; 
    while (n--) {
        *psrc++ = (char)c;
    }
    return src;
}
// ====================================================================

int main()
{
    int nums[10];
    memset(nums, -1, 10*sizeof(int));
    print(nums, 10);

// -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

    return 0;
}