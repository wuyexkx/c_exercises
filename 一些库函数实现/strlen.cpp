#include <iostream>
#include <cassert>
#include "test.h"

// ==============================================================
size_t strlen(const char* str)
{
    assert(str != NULL);
    size_t n = 0;
    while (*str != '\0') {
        str++;
        n++;
    }
    return n;
}
// ==============================================================


int main()
{
    const char* str = "hello!";
    std::cout << strlen(str) << std::endl;
    
    // 6

    return 0;
}