#include <stdio.h>

typedef unsigned int uint;

#define PI (3.1415927)


/*
计算球的体积
根据输入的半径值，计算球的体积。

输入 输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。
输出 输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。
*/

/*
Note:
   球的体积： V = 4/3 * pi * r^3
   球的表面积： S = 4 * pi * r^2
*/

void jisuanqiudetizhi()
{
    double r;

    printf("please enter the radius of the ball: ");
    while(scanf("%lf", &r)){
        printf("V: %.3lf\n", 4.0/3.0 * PI * r * r * r);
        printf("S: %.3lf\n", 4 * PI * r * r);
    }
}

int main()
{
    jisuanqiudetizhi();

    return 0;
}
