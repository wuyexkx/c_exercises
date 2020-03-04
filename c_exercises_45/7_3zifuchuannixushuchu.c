#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
字符串逆序输出
给定一行字符，逆序输出此行（空格.数字不输出）

输入
第一行是一个整数N(N<10)表示测试数据的组数） 每组测试数据占一行，
每行数据中间有且只有一个空格（这样你可以把此行当成两个字符串读取）。 
每行字符长度不超过40 并且保证输入的字符只有空格（1个），数字，小写字母三种

输出 对应每行测试数据，逆序输出（空格和数字不输出）

Ex: 
    abc de.f.g
    gfedcba
*/

/*
Note:
    gets可以接收空格，遇到回车结束
    而scanf遇到空格、回车和Tab键都会认为输入结束，所有它不能接收空格。

    字符串结束都加'\0'
        注意gets会接收缓冲区输入的内容，需要用getchar释放掉再gets
*/

void zifuchuannixushuchu()
{
    int N;
    char strs[41];
    int length, max=0;
    scanf("%d", &N);
    getchar();
    while(N--){  
        gets(strs);
        length = strlen(strs);
        for(int i=length-1; i>=0; --i){
            if(strs[i] == '.' || strs[i] == ' ' || (strs[i] > '0' && strs[i] < '9')){ 
            }
            else{
                printf("%c", strs[i]);
            }
        }
    }
}

int main()
{
    zifuchuannixushuchu();

    return 0;
}
