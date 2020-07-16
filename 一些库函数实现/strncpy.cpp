#include <iostream>
#include <cassert>
#include "test.h"

// ===========================================================
// 复制指定长度的字符串，末尾\0
char* strncpy(char* dest, const char* src, size_t n)
{
    assert(dest != NULL && src != NULL);

    char* ret = dest;
    const char* psrc = src;
    size_t lensrc = 0;
    while (*psrc++ != '\0') lensrc++;

    n = lensrc > n ? n : lensrc;

    if (dest > src && dest < src + n) {
        dest += n;
        *dest-- = '\0';
        src += n - 1;
        while (n--) {
            *dest-- = *src--;
        }
    } else {
        while (n--) {
            *dest++ = *src++;
        }
        if (*(dest - 1) != '\0') *dest = '\0';
    }
    return ret;
}
// =============================================================

int main()
{
    char src[20] = "hello world!";
    char* dest = &src[0] + 3;
    printf("src : %s\n", src);

    strncpy(dest, src, 7);
    printf("src : %s\n", src);
    printf("dest: %s\n", dest);

    // src : hello world!
    // src : helhello w
    // dest: hello w

    return 0;
}