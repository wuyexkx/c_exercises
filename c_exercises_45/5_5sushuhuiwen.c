#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h> 
typedef unsigned int uint;

/*
素数回文
xiaoou33对既是素数又是回文的数特别感兴趣。
比如说151既是素数又是个回文。
现在xiaoou333想要你帮助他找出某个范围内的素数回文数，
请你写个程序找出 a 跟b 之间满足条件的数。(5 <= a < b <= 100,000,000);

输入 这里有许多组数据，每组包括两组数据a跟b。
输出 对每一组数据,
    按从小到大输出a，b之间所有满足条件的素数回文数（包括a跟b）每组数据之后空一行。
*/

/*
Note:
*/

void sushuhuiwen()
{
    uint num1, num2;
    uint d[9];

    while(scanf("%d %d", &num1, &num2) != EOF){
        // 1. 回文数
        // 按照位数寻找
        for(uint num=num1; num<=num2; ++num){  
            /* // 获得当前数的位数( 我的垃圾代码)
            uint rate = 1, digits=0;
            while(num >= rate){
                rate *= 10;
                ++digits;
            } 
            // 拆分当前数的各个位
            uint temp = num;
            rate = 1;
            for(int i=0; i<digits-1; ++i) rate *= 10; // 最大倍率
            for(int i=0; i<digits; ++i){
                d[i] = temp / rate;  // 取最高位
                temp = temp % rate;  // 保留余数
                rate /= 10;          // 倍率依次降低 1000 100 10 1
            }  */
            
            // 拆分当前数的各个位 并得到位数
            uint digits=0, temp=num;
            while(temp != 0){
                d[digits] = temp % 10; // 取出个位
                temp /= 10;            // 用商更新 
                ++digits;
            }
            // 比较对应高低位
            uint num_equal=0;
            for(int i=0; i<digits; ++i){
                if(d[i] == d[digits-1-i])
                    ++num_equal;
            }
            // 满足条件则回文数
            if(num_equal == digits){ 
                // printf("huiwen:%d ", num);

        // 2. 判断是否素数
                uint i;
                for(i=2; i<num; ++i){
                    if(num % i == 0)
                        break;
                }
                if(i == num)
                    printf("%d ", num); 
            }   
            digits = 0;
        }
    }
}


int main()
{
    sushuhuiwen();

    return 0;
}
