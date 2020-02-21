#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
奇偶数分离
有一个整型偶数n(2<= n <=10000),你要做的是：
先把1到n中的所有奇数从小到大输出，再把所有的偶数从小到大输出。

输入 第一行有一个整数i（2<=i<30)表示有 i 组测试数据；每组有一个整型偶数n。
输出 第一行输出所有的奇数。第二行输出所有的偶数
*/

/*
Note:
    
*/

void jioushufenli()
{
    int T, num, temp;   

    printf("input number of all data:");
    scanf("%d", &T);      
    while(T--){
        printf("input a even num (2~10000):");   
        scanf("%d", &num);
        printf("(1~n) even:");
        for(int i=1; i<=num; ++i){
            if(i % 2 == 0)
                printf("%d ", i);
        }
        printf("\n(1~n) odd:");
        for(int i=1; i<=num; ++i){
            if(i % 2 != 0)
                printf("%d ", i);
        }
        printf("\n");
    }
}

int main()
{
    jioushufenli();

    return 0;
}
