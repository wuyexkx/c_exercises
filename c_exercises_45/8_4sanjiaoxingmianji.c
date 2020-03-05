#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
三角形面积
给你三个点，表示一个三角形的三个顶点，现你的任务是求出该三角形的面积

输入 每行是一组测试数据，
有6个整数x1,y1,x2,y2,x3,y3分别表示三个点的横纵坐标。
（坐标值都在0到10000之间）输入0 0 0 0 0 0表示输入结束。
测试数据不超过10000组

输出 输出这三个点所代表的三角形的面积，
结果精确到小数点后1位（即使是整数也要输出一位小数位）
*/

/*
Note:
    1. 直接求
        S = 1/2[(xa(yb-yc) + xb(yc-ya) + xc(ya-yb))]
        S = 0.5 * fabs(xa*(yb-yc) + xb*(yc-ya) + xc*(ya-yb));
    2. 海伦公式：
        a b c                       求边长
        p=(a+b+c)/2                 半周长
        S=sqrt(p(p-a)(p-b)(p-c))    面积  
*/

void sanjiaoxingmianji()
{
    float S;
    int xa, ya, xb, yb, xc, yc;

    while(scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc) != EOF){  
        if(!(xa+ya+xb+yb+xc+yc)) break;

        S = 0.5 * fabs(xa*(yb-yc) + xb*(yc-ya) + xc*(ya-yb));

        printf("%.1f\n", S);
    }
}


int main()
{
    sanjiaoxingmianji();

    return 0;
}
