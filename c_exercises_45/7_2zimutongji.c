#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

// /*
// 字母统计
// 现在给你一个由小写字母组成字符串，要你找出字符串中出现次数最多的字母，
// 如果出现次数最多字母有多个那么输出最小的那个。

// 输入 第一行输入一个正整数T（0<T<25）随后T行输入一个字符串s, 
// s长度小于1010。
// 输出 每组数据输出占一行，输出出现次数最多的字符；

// 如： abcdeeefggg --> e
// */

// /*
// Note:
// 用字母的索引保存计数值，巧用'a'-0  'a'+0
// */

void zimutongji()
{
    int T;
    char strs[1011];
    int count[26];
    int length, max=0;
    memset(count, 0, sizeof(int) * 26);
    scanf("%d", &T);
    while(scanf("%s", strs) != EOF){  
        length = strlen(strs);
        // 计数
        for(int i=0; i< length; ++i){
            count[strs[i] - 'a']++;
        }
        // 查找计数最大值
        for(int i=0; i<26; ++i){
            if(count[i] > max){
                max = count[i];
            }
        }
        // 根据最大值输出最多的字符。若有多个输出最小的即可
        for(int i=0; i<26; ++i){
            if(count[i] == max){
                printf("%c\n", 'a'+i);
                break;
            }
        }
    }
}

int main()
{
    zimutongji();

    return 0;
}
