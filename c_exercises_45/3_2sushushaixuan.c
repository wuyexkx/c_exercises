#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
素数筛子算法
现在给你一个正整数N，要你快速的找出在2.....N这些数里面所有的素数。

输入 给出一个正整数数N(N<=2000000)、但N为0时结束程序。、测试数据不超过100组
输出 将2~N范围内所有的素数输出。两个数之间用空格隔开
*/

/*
Note:
    素数（质数）是指除了1和它本身以外，不能被任何整数整除的数，2是最小的素数。
    例如17就是素数，因为它不能被 2~16 的任一整数整除。
*/

void sushushaixuan()
{
    uint T=100, num, result, cnt=0;             
    while(T-- > 0 && scanf("%d", &num) != EOF){
        printf( "input a positive number:");
        if(num == 1){
            printf( "1 is not a prime number.\n");
        }
        else if(num == 2){
            printf( "0~2 prime numbers:2\n");
        }
        else{ // 主要部分
            printf( "0~%d prime numbers:", num);
            for(uint i=2; i<=num; ++i){
                int flag = 0;
                for(uint j=2; j<i; ++j){
                    if(i%j == 0){ // 在2~i-1之间找到一个可以被整除的就不是
                        j = 2;
                        flag = 1;
                        break;
                    } 
                }
                if(flag == 0){
                    printf("%d ", i);
                    ++cnt;
                }
            }
        }
        printf("total: %d\n", cnt);
        cnt = 0;
    }
}

int main()
{
    sushushaixuan();

    return 0;
}

