#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
首字母变大写
输入一个英文句子，将每个单词的第一个字母改成大写字母。

输入 输入数据包含多个测试实例，
每个测试实例是一个长度不超过100的英文句子，占一行。

输出 请输出按照要求改写后的英文句子。
*/

/*
Note:
    1. 输入一个处理一个
        islower(c) 判断是不是小写
        toupper(c) 变成大写
        
    2. 输入完挨个处理
*/

void shouzimubiandaxie()
{
    char strs[101];
    // 不能用scanf, 它碰到空格就结束
    while(gets(strs)){  
        // 第一个首字母
        if(strs[0] >= 'a' && strs[0] <= 'z'){
            strs[0] = strs[0] - 'a' + 'A';
        }
        // 其他首字母 
        int length = strlen(strs);
        for(int i=0; i<length-1; ++i){
            if(strs[i] == ' '){
                if(strs[i+1] >= 'a' && strs[i+1] <= 'z'){
                    strs[i+1] = strs[i+1] - 'a' + 'A';
                }
            }
        }
        // 输出
        for(int i=0; i<length; ++i){
            printf("%c", strs[i]);
        }

    }
}


int main()
{
    shouzimubiandaxie();

    return 0;
}
