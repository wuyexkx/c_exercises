#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
猴子吃桃问题
有一堆桃子不知数目，猴子第一天吃掉一半，又多吃了一个，
第二天照此方法，吃掉剩下桃子的一半又多一个，天天如此，
到第m天早上，猴子发现只剩一只桃子了，问这堆桃子原来有多少个？ (m<29)

输入 第一行有一个整数n,表示有n组测试数据
（从第二行开始，每一行的数据为：第m天）；
输出 每一行数据是桃子的总个数
*/

/*
Note:
    1. 顺着题目的意思去，做减法 x = x * 1/2 - 1
    2. 逆向, 做加法    x = (x + 1) * 2
*/

void houzichitaowenti()
{
    int n, m;
    scanf("%d", &n);
    while(n-- && scanf("%d", &m) != EOF){  
        // 做减法
        // int all = 3, result;
        // while(++all){
        //     result = all;
        //     int i=0;
        //     for(; i<m-1; ++i){
        //         all = all / 2 - 1;
        //     }
        //     if(all == 1){
        //         printf("%d\n", result);
        //         break;
        //     }
        //     all = result;
        // }

        // 做加法
        int result = 1;
        for(int i=0; i<m-1; ++i){
            result = (result + 1) * 2;
        }
        printf("%d\n", result);
    }
}


int main()
{
    houzichitaowenti();

    return 0;
}
