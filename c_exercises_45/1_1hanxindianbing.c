#include <stdio.h>

typedef unsigned int uint;

/*
韩信点兵
相传韩信才智过人，从不直接清点自己军队的人数，
只要让士兵先后以三人一排、五人一排、七人一排地变换队形，
而他每次只掠一眼队伍的排尾就知道总人数了。
输入3个非负整数a,b,c ，表示每种队形排尾的人数（a<3,b<5,c<7），
输出总人数的最小值（或报告无解）。
已知总人数不小于10，不超过100 。

*/

void hanxin_count(uint a, uint b, uint c)
{
    for(int n=10; n<101; ++n) {
        if((n%3 == a) && (n%5 == b) && (n%7 == c)) {
            printf("at least: %d\n", n);
            return;
        }
    }
    printf("No answer.\n");
}

int main()
{
    uint a, b, c;
    printf("\nPlease enter 3 numbers separated by 'space': ");
    scanf("%d %d %d", &a, &b, &c);

    hanxin_count(a, b, c);

    return 0;
}