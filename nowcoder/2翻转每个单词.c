#include <stdio.h>
#include <string.h>

int main()
{
    char s[100001];
    while (scanf("%s", s) != EOF) // scanf读取是遇到 空格 或 \0就结束
    {
        int len = strlen(s);
        for (int i=0; i<len/2; ++i) {
            s[i] = s[i] ^ s[len-i-1];
            s[len-i-1] = s[i] ^ s[len-i-1];
            s[i] = s[i] ^ s[len-i-1];
        }
        printf("%s ", s);
    }
    printf("\n");
    return 0;
}

// python代码 3行
// s = input().split()
// for i in s:
//     print(i[::-1], end = ' ')