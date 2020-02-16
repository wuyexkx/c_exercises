#include <stdio.h>
#include <math.h>
typedef unsigned int uint;

/*
两点距离
输入两点坐标（X1,Y1）,（X2,Y2）(0<=x1,x2,y1,y2<=1000),计算并输出两点间的距离。

输入 第一行输入一个整数n（0<n<=1000）,表示有n组测试数据;随后每组占一行，由4个实数组成，分别表示x1,y1,x2,y2,数据之间用空格隔开。
输出 对于每组输入数据，输出一行，结果保留两位小数。
*/

/*
Note:
    距离公式： sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) )
*/

void liangdianjuli()
{
    double x1, y1, x2, y2;
    uint n;

    printf("\nplease enter total: ");
    scanf("%d", &n);

    while(n--){
        printf("\nPlease enter the coordinates of 2 points, x1  y1  x2  y2: ");
        scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
        
        printf( "2 points distance: %.2lf\n", 
                sqrt( (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) ) );
    }
}

int main()
{
    liangdianjuli();

    return 0;
}
