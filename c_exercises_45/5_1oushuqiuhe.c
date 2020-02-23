#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h> 
typedef unsigned int uint;

/*
偶数求和
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，
现在要求你按照顺序每m个数求出一个平均值，
如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。

输入 输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。
输出 对于每组输入数据，输出一个平均值序列，每组输出占一行。
*/

/*
Note:
    示例：
    // 2 4  6 8  10 12   n=6 m=2
    //  3    7    11     

    // 2 4  6 8  10   n=5 m=2
    //  3    7   10  
*/

void oushuqiuhe()
{
    uint n, m, result=0;
    uint nums[100]; 

    scanf("%d %d", &n, &m);
    for(uint i=1; i<=n; ++i){
        nums[i-1] = 2*i;
    }

    uint quotient=n/m, remainder=n%m;
    // 整数倍
    for(uint i=1; i<=quotient; ++i){
        for(uint j=(i-1)*m; j<i*m; ++j){
            result += nums[j];            
        }
        printf("%d ", result/m);
        result = 0;
    }
    // 余下的平均值
    if(remainder != 0){
        for(uint i=n-1; i>n-1-remainder; --i){
            result += nums[i];
        }
        printf("%d ", result/remainder);
    } 
    
    printf("\n");
}

int main()
{
    oushuqiuhe();

    return 0;
}
