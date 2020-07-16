#include <iostream>
#include <cassert>
#include "test.h"

// =================================================
// 字符串比较 '\0'(0)
int strcmp(const char* s1, const char* s2)
{
    assert(s1 != NULL && s2 != NULL);
    while (*s1 && *s2 && *s1 == *s2) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
// =================================================

int main()
{
    const char* s1 = "hello!";
    const char* s2 = "hello! ";

    std::cout << strcmp(s1, s2) << std::endl;

// -32

    return 0;
}
