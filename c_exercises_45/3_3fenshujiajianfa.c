#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
编写一个C程序，实现两个分数的加减法

输入
输入包含多行数据 每行数据是一个字符串，格式是"a/boc/d"。 
其中a, b, c, d是一个0-9的整数。o是运算符"+"或者"-"。 数据以EOF结束 输入数据保证合法

输出 对于输入数据的每一行输出两个分数的运算结果。
注意结果应符合书写习惯，没有多余的符号、分子、分母，并且化简至最简分数
*/

/*
Note:

*/
uint gcd(uint a, uint b)
{
    uint temp;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 假设分母输入都是正数
void fenshujiajianfa()
{
    int a, b, c, d, num, den;   
    char sign;          
    while(scanf("%d/%d%c%d/%d", &a, &b, &sign, &c, &d) != EOF){
        uint _gcd;

        if(sign == '-')
            num = a*d - c*b; // 得到数分子
        else if(sign == '+')
            num = a*d + c*b; // 得到数分子

        if(num == 0){
            printf("Simplify to get the final result:0\n");
            continue;
        }
        else if(num < 0){
            _gcd = gcd(-num, b*d);
            printf("Simplify to get the final result:-%d/%d\n", -num/_gcd, b*d/_gcd);
        }
        else {
            _gcd = gcd(num, b*d);
            printf("Simplify to get the final result:%d/%d\n", num/_gcd, b*d/_gcd);           
        }
    }
}

int main()
{
    fenshujiajianfa();

    return 0;
}

