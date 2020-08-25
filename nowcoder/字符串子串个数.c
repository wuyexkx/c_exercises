// g++ -o main test.cpp && ./main

#include <stdio.h>
#include <string.h>

// 输入 qwertqwas qw
// 输出 2
int del_sub(char* str, char* sub)
{
    int len1 = strlen(str);
    int len2 = strlen(sub);
    if (len1 == 0 || len2 == 0) return 0;
    
    int count = 0;
    for (int i = 0; i < len1; i++) {
        int j = 1;
        if (str[i] == sub[0]) {
            int ii = i;
            for (; j < len2; j++) {
                if (str[ii + 1] != sub[j]) {
                    break;
                }
                ii++;
            }
            if (j == len2) count++;
        }
    }
    return count;
}


int main(void)
{
    char str[100];
    char sub[100];
    int num = 0;
    scanf("%s", str);
    scanf("%s", sub);
    num = del_sub(str, sub);
    printf("%d", num);
    
    return 0;
}