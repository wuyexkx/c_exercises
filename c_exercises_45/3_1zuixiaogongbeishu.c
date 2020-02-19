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

for(i=min; i<=min; i--) { //当三个数同时被i整除，此时i为三个数对的最大公约数
    if(num1%i==0 && num2%i==0 && num3%i==0) { 
        break;
    }
}
for(j=max;;j++) {         //当j能被三个数同时整除，j为三个数的最小公倍数
    if(j%num1==0 && j%num2==0 && j%num3==0) { 
        break;
    }
}
*/

// 两个数的最大公约数和最小公倍数（辗转相除法）
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
        // 到这里a是最大公约数
        // 再根据 最大公约数 求最小公倍数
        result = m * n / a;
        printf( "The Greatest Common Divisor (GCD):%d\n", a);
        printf( "The Least Common Multiple (LCM):%d\n", result);
    }
}

// n个数的最大公约数和小公倍数
//  最大公约数：最小数递减，直到能被所有数整除
//  最小公倍数：最大数累加，直到能整除所有数
void GCD_LCM_n()
{
    uint n, min=(uint)(pow(2, sizeof(uint) * 8) - 1), max=0;             

    printf("input n: ");
    scanf("%d", &n);   
    uint *nums = (uint *)malloc(sizeof(uint) * n);
    printf("all number: ");
    for(uint i=0; i<n; ++i){
        scanf("%d", &nums[i]);

        if(nums[i] < min){
            min = nums[i];
        }
        if(nums[i] > max){
            max = nums[i];
        }
    }
    printf("max=%d, min=%d\n", max, min);

    // 最大公约数，min往下减
    for(uint i=0; i<n; ++i){
        if(nums[i] % min != 0){
            --min;
            i = 0;
        }
    }
    // 最小公倍数
    for(uint i=0; i<n; ++i){
        if(max % nums[i] != 0){
            ++max;
            i = 0;
        }
    }
    free(nums);

    printf( "The Greatest Common Divisor (GCD):%d\n", min);
    printf( "The Least Common Multiple (LCM):%d\n", max);
}

// n个数的最小公倍数，自己写的垃圾代码
//   找最小数的整数倍，满足所有数能被整除的最小的那个
void zuixiaogongbeishu_n()
{
    uint n, minimum = (uint)(pow(2, sizeof(uint) * 8) - 1);             

    printf("input n: ");
    scanf("%d", &n);   
    uint *nums = (uint *)malloc(sizeof(uint) * n);
    printf("all number: ");
    for(int i=0; i<n; ++i){
        scanf("%d", &nums[i]);
        if(nums[i] < minimum)
            minimum = nums[i];
    }
    printf( "min:%d\n", minimum);

    // 找最小数的整数倍，满足所有数能被整除的最小的那个
    uint rate=2, result=minimum;
    for(uint i=0; i<n; ++i){
        if(result % nums[i] != 0){
            result = minimum * rate;
            ++rate;
            i = 0;
        }
    }
    free(nums);
    printf( "The Least Common Multiple (LCM):%d\n", result);
}


int main()
{
    // zuixiaogongbeishu();

    // zuixiaogongbeishu_n();
    GCD_LCM_n();

    return 0;
}

