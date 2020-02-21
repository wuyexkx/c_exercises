#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
统计硬币
假设一堆由1分、2分、5分组成的n个硬币总面值为m分，
求一共有多少种可能的组合方式（某种面值的硬币可以数量可以为0）。

输入 输入数据第一行有一个正整数T，表示有T组测试数据；
接下来的T行，每行有两个数n,m，n和m的含义同上。
输出 对于每组测试数据，请输出可能的组合方式数；每组输出占一行。
*/

/*
Note:
    寻找 满足 a*1+b*2+c*5=score && a+b+c=num 的a b c的整数解 的个数
*/

void tongjiyingbi()
{
    int T, num, score;
    uint a_max, b_max, c_max, result=0;

    printf("input group num:");
    scanf("%d", &T);      
    while(T--){
        printf("input n(number of coin) m(score):");
        scanf("%d %d", &num, &score); 
        a_max = score / 1;
        b_max = score / 2;
        c_max = score / 5;

        printf("Possible ways (1 2 5):\n");
        for(int a=0; a<=a_max; ++a){
            for(int b=0; b<=b_max; ++b){
                for(int c=0; c<=c_max; ++c){
                    if(a+b+c==num && a*1+b*2+c*5==score){
                        ++result;
                        printf("       num%d    %d %d %d\n", result, a, b, c);
                    }
                }
            }
        }
        printf("total: %d\n", result);
        result = 0;
    }
}

int main()
{
    tongjiyingbi();

    return 0;
}
