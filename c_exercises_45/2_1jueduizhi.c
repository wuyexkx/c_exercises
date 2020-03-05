#include <stdio.h>

typedef unsigned int uint;

/*
求实数的绝对值。
输入 输入数据有多组，每组占一行，每行包含一个实数。
输出 对于每组输入数据，输出它的绝对值，要求每组数据输出一行，结果保留两位小数。
*/


/*
Note:
    1. 输入数据的类型 及 格式 double, %lf
    2. 输出数据的格式控制，%.2lf
*/

void jueduizhi()
{
    double num;

    printf("please enter a num: ");
    while(scanf("%lf", &num)){
        if(num < 0)
            num = -num;
        printf("degree: %.2lf\n", num);
    }
}

int main()
{
    jueduizhi();

    return 0;
}
