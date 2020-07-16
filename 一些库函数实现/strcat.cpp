#include <iostream>
#include <cassert>
#include "test.h"

// =================================================
// 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾
char* strcat(char* dest, const char* src)
{
    assert(dest != NULL && src != NULL);
    char* ret = dest;
    while (*dest != '\0') {
        dest++;
    }
    while ((*dest++ = *src++) != '\0');

    return ret;
}
// =================================================

int main()
{
    char src[10] = "world!";
    char dest[20] = "hello ";

    strcat(dest, src);
    printf("%s\n", dest);

    // hello world!

    return 0;
}
