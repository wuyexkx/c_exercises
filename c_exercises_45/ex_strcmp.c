#include <stdio.h>

// 依次比较字符，ASCII码
int ex_strcmp(const char*const s1, const char*const s2)
{
    unsigned int i=0;
    while(s1[i] == s2[i] && s1[i] != '\0') ++i;
    if(s1[i] == '\0' && s2[i] == '\0') 
        return 0;     // equal
    if(s1[i] > s2[i])
        return 1;     // s1 larger
    else
        return -1;    // s2 larger
}

int main()
{
    char s1[100] = {"abcdfed"};
    char s2[100] = {"abcdfede"};

    printf("%d\n", ex_strcmp(s1, s2));
    return 0;
}