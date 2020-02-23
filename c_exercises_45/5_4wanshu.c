#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h> 
typedef unsigned int uint;

/*
完数
完数的定义：如果一个大于1的正整数的所有因子之和等于它的本身，
则称这个数是完数，比如6，28都是完数：6=1+2+3；28=1+2+4+7+14。

输入 输入数据包含多行，第一行是一个正整数n，表示测试实例的个数，
然后就是n个测试实例，每个实例占一行，由两个正整数num1和num2组成,(1<num1,num2<10000) 。
输出 对于每组测试数据，请输出num1和num2之间（包括num1和num2）存在的完数个数。
*/

/*
Note:
其实在(1~1000000)之间只有4个  6 28 496 8128 
*/

void wanshu()
{
    uint T, num1, num2, result=0;
    uint factors[1000], n_divided=0;

    scanf("%d", &T);
    while(T-- && scanf("%d %d", &num1, &num2)){
        for(uint index=num1; index<=num2; ++index){
            for(uint j=1; j<index; ++j){ // 从1~num-1依次检查能否被整除
                if(index%j == 0){       // 记录能被整除的数
                    factors[n_divided] = j;
                    ++n_divided;
                }
            }
            uint temp = 0;
            for(uint i=0; i<n_divided; ++i){    // 查看能被整除的数之和 是否等于这个数
                temp += factors[i];
            }
            if(temp == index){
                ++result;
                printf("%d ", index);
            }
            n_divided = 0;
        }
        printf("(%d~%d) nummbers of wanshu: %d\n", num1, num2, result);
        result = 0;
    }
}

int main()
{
    wanshu();

    return 0;
}
