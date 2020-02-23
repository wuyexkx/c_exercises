#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h> 
typedef unsigned int uint;

/*
统计字符
统计一个给定字符串中指定的字符出现的次数

输入 测试输入包含若干测试用例，每个测试用例包含2行，
第1行为一个长度不超过5的字符串，第2行为一个长度不超过80的字符串。
注意这里的字符串包含空格，即空格也可能是要求被统计的字符之一。
当读到'#'时输入结束，相应的结果不要输出。

输出
对每个测试用例，统计第1行中字符串的每个字符在第2行字符串中出现的次数，
按如下格式输出： c0 n0 c1 n1 c2 n2 ... 其中ci是第1行中第i个字符，ni是ci出现的次数。
*/

/*
Note:
*/

void tongjizifu()
{
    uint n1=0, n2=0;
    char c1[6], c2[81];
    uint num[5]={0,0,0,0,0};

    while(gets(c1) && gets(c2)){
        // 计数输入字符个数
        n1 = strlen(c1);
        n2 = strlen(c2) - 1;
        // 比较计数
        for(uint i=0; i<n1; ++i){
            for(uint j=0; j<n2; ++j){
                if(c1[i] == c2[j])
                    ++num[i];
            }
        }
        // 输出
        for(uint i=0; i<n1; ++i){
            printf("%c %d ", c1[i], num[i]);
        }
        // 清零
        for(uint i=0; i<n1; ++i){
            num[i] = 0;
        }        
        n1 = n2 = 0;
        printf("\n");
    }
}

int main()
{
    tongjizifu();

    return 0;
}
