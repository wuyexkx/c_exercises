#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
最小公倍数
给定两个正整数，计算这两个数的最小公倍数。

输入 输入包含多组测试数据，每组只有一行，包括两个不大于1000的正整数.
输出 对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。
*/

/*
Note:
最小公倍数 = 乘积 / 最大公约数
最大公约数，用辗转相除法（欧几里得法）得到最大公约数：
    如：27和15
        27 % 15 = 12
        15 % 12 = 3
        12 % 3 = 0
        所以3是27和15的最大公约数，
        最小公倍数为 27 * 15 / 3 = 135
*/

// 两个数的最大公约数和最小公倍数
void zuixiaogongbeishu()
{
    uint a, b;             
    while(scanf("%d %d", &a, &b) != EOF){
        uint result=0, m=a, n=b, temp;

        // 先求最大公约数（辗转相除法）
        while(b != 0) { 
            temp = a % b;
            a = b;
            b = temp;
        }
        // 到这里a是最小公倍数
        // 再根据 最大公约数 求最小公倍数
        result = m * n / a;
        printf( "The largest common divisor:%d\n", a);
        printf( "The least common multiple:%d\n", result);
    }
}

// n个数的最小公倍数
void zuixiaogongbeishu_n()
{
    uint n, a, b;             

    printf("input n: ");
    scanf("%d", &n);   
    uint *nums = (uint *)malloc(sizeof(uint) * n);
    printf("all number: ");
    for(int i=0; i<n; ++i){
        scanf("%d", &nums[i]);
    }
    uint minimum = (uint)pow(2, sizeof(uint)*8);

    for(int i=0; i<n; ++i){
        if(nums[i] < minimum)
            minimum = nums[i];
    }

    /* 寻找n个数的最小公倍数 */ 
    uint i=1, result;
    uint index = 0;
    // 外层循环提供 最小数的i倍
    while(index != n){
        result = minimum * i; // 最小数的倍数
        index = 0;
        // 内层循环 依次除每个数，直到所有数都能整除为止
        while(index!=n && result%nums[index] == 0){
            ++index;
        }
        ++i;
    }
    free(nums);
    printf( "The least common multiple:%d\n", result);
}

int main()
{
    zuixiaogongbeishu();
    // zuixiaogongbeishu_n();

    return 0;
}
