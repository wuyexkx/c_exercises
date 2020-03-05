#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
a/b + c/d
给你2个分数，求他们的和，并要求和为最简形式。

输入 输入首先包含一个正整数T（T<=1000），
表示有T组测试数据，然后是T行数据，
每行包含四个正整数a,b,c,d（0<a,b,c,d<1000），表示两个分数a/b 和 c/d。

输出 对于每组测试数据，输出两个整数e和f，
表示a/b + c/d的最简化结果是e/f，每组输出占一行。
*/

/*
Note:

*/

void acbjccd()
{
    int T;
    int a, b, c, d;
    scanf("%d", &T);
    while(T-- && scanf("%d%d%d%d", &a, &b, &c, &d)){  
        //  a/b + c/d
        int e, f;
        // 约分前分子
        e = a * d + c * b;
        // 约分前分母
        f = b * d;
        // 寻找最大公约数（最小公倍数=乘积/最大公约数）
        int x = e, y = f, t;    // 12 9  12%9=3 9%3=0
        while(y != 0){
            t = x % y;
            x = y;
            y = t;
        }
        printf("%d/%d\n", e/x, f/x);
    }
}


int main()
{
    acbjccd();

    return 0;
}
