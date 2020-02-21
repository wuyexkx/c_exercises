#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
第二小整数
求n个整数中倒数第二小的数。每一个整数都独立看成一个数，
比如，有三个数分别是1，1，3，那么，第二小的数就是1。

输入
输入包含多组测试数据。 输入的第一行是一个整数C，表示有C测试数据； 
每组测试数据的第一行是一个整数n，表示本组测试数据有n个整数（2<=n<=10），
接着一行是 n个整数 (每个数均小于100);

输出 请为每组测试数据输出第二小的整数，每组输出占一行。
*/

/*
Note:
    先找到最小值，再排除最小值找到次小值
*/

void dierxiaozhengshu()
{
    int T, n, min, sec_min, MAX;   
    MAX = (int)(pow(2, sizeof(int)*8-1)-1);
    sec_min = min = MAX;

    printf("input number of all data:");
    scanf("%d", &T);      
    while(T--){
        printf("input data:");   
        scanf("%d", &n);
        int *nums = (int *)malloc(sizeof(int) * n);
        for(int i=0; i<n; ++i){
            scanf("%d", &nums[i]);
            if(nums[i] < min)
                min = nums[i];
        }
        // 遍历查找倒数第二数
        for(int i=0; i<n; ++i){
            if(nums[i] < sec_min && nums[i] != min)  // 如果不是最小数 并且 是其他数中最小的
                sec_min = nums[i]; // 保存次小值
        }
        if(sec_min == MAX) // 次小值可能没有更新，可能次小的就是最小的
            sec_min = min;
        
        free(nums);        
        printf("second smallest:%d\n", sec_min);
    }
}

int main()
{
    dierxiaozhengshu();

    return 0;
}
