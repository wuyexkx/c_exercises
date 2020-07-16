#include <iostream>
#include <cassert>
#include <cstring>
#include "test.h"

// ==============================================================
// // 未考虑重叠情况
// char* strcpy(char* dest, const char* src)
// {
//     assert(dest != NULL && src != NULL);
    
//     char* ret = dest;
//     while ((*dest++ = *src++) != '\0');

//     return ret;
// }

char* strcpy(char* dest, const char* src)
{
    assert(dest != NULL && src != NULL);
    char* pdst = dest;
    size_t n = strlen(src);

    if (dest > src && dest < src + n) {
        src += n - 1;
        pdst += n;
        *pdst-- = '\0';
        while (n--) {
            *pdst-- = *src--;
        }
    }
    else {
        while ((*pdst++ = *src++) != '\0');
    }
    return dest;
}
// ==============================================================


int main()
{
    char s1[10] = "hello!";
    char s2[10];
    strcpy(s2, s1);
    printf("s1: %s\n", s1);
    printf("s2: %s\n\n", s2);


    char* src1 = (char*)malloc(10*sizeof(char));
    char* dest1 = src1 + 3;

    strcpy(src1, "hello!");
    printf("src1: %s\n", src1);
    strcpy(dest1, src1);
    printf("src1: %s\n", src1);
    printf("dest1: %s\n", dest1);

    // s1: hello!
    // s2: hello!

    // src1: hello!
    // src1: helhello!
    // dest1: hello!

    return 0;
}
