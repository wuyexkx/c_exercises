#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
绝对值排序
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。
题目保证对于每一个测试实例，所有的数的绝对值都不相等。

输入 输入数据有多组，每组占一行，每行的第一个数字为n,
接着是n个整数，n=0表示输入数据的结束，不做处理
输出 对于每个测试实例，输出排序后的结果，
两个数之间用一个空格隔开。每个测试实例占一行。
*/

/*
Note:
    也许题目有的条件是迷惑性的，比如这个：
        输入不管是不是绝对值不等的，都可以用冒泡绝对值排序
*/

void jueduizhipaixu()
{
    int m, n;
    int nums[100];
    while(1){  
        scanf("%d", &n);
        int temp;
        for(int i=0; i<n; ++i){
            scanf("%d", &nums[i]);
        }
        // 按绝对值排序，冒泡
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(fabs(nums[i]) < fabs(nums[j])){
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
        // 输出
        for(int i=0; i<n; ++i){
            printf("%d ", nums[i]);
        }
    }
}


int main()
{
    jueduizhipaixu();

    return 0;
}
