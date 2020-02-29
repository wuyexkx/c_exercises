#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

#define TEMPLATE int
#include "stack_macro.h"

typedef unsigned int uint;

/*
快速排序
给你n个整数，请按从大到小的顺序输出其中前m大的数。

输入 每组测试数据有两行，第一行有两个数n,m(0<n,m<1000000)，
第二行包含n个各不相同，且都处于区间[-500000,500000]的整数。

输出 对每组测试数据按从大到小的顺序输出前m大的数。
*/

/*
Note:
    快速排序，用到递归。
    1.选定左边的数为轴
    2.从右往前与轴比较,当找到一个或者没有找到<轴的数的时候,开始从左往右查找
    3.重点是划分为两部分的方法
*/


// 1. 递归实现快速排序， 跟轴p比较，寻找l，
void qsort1(int nums[], const int left, const int right)
{
    if(left > right) return;
    int p=nums[left], l=left, r=right;
    while(l < r){
        while(l<r && nums[r]>=p) --r;
        if(l < r) nums[l++] = nums[r];

        while(l<r && nums[l]<p) ++l;
        if(l < r) nums[r--] = nums[l];
    }
    nums[l] = p;

    qsort1(nums, left, l-1);
    qsort1(nums, l+1, right);
}

// 2. 非递归实现快速排序，需要用到栈
void qsort2(int nums[], int left, int right)
{
    stack(int) s1 = init(stack(int));

    s1.push(&s1, &left);
    s1.push(&s1, &right);

    int l, r, p;
    while(!s1.empty(&s1)){
        int right = s1.pop(&s1);
        int left = s1.pop(&s1);
        if(left < right){
            l = left;
            r = right;
            // -----------划分区间----------------
            p = nums[left];
            while(l < r){
                while(l<r && nums[r]>=p) --r;
                if(l < r) nums[l++] = nums[r];
                while(l<r && nums[l]<p) ++l;
                if(l < r) nums[r--] = nums[l];
            }
            nums[l] = p;
            // -----------------------------------
            int b = l;
            s1.push(&s1, &left);
            s1.push(&s1, &b);
            b += 1;
            s1.push(&s1, &b);
            s1.push(&s1, &right);
        }
    }
    s1.free(&s1);
}

void kuaisupaixu()
{
    uint n, m;

    while(scanf("%d %d", &n, &m) != EOF){
        int * nums = (int *)malloc( sizeof(int)*n );
        printf("input numbers:");
        for(int i=0; i<n; ++i){
            scanf("%d", &nums[i]);
        }
    // 快速排序
    // qsort1(nums, 0, n-1);
    qsort2(nums, 0, n-1);


        // // 1. 冒泡排序
        // int temp;
        // for(int i=0; i<n; ++i){
        //     for(int j=i+1; j<n; ++j){
        //         if(nums[j] < nums[i]){
        //             temp = nums[i];
        //             nums[i] = nums[j];
        //             nums[j] = temp;
        //         }
        //     }
        // }

        // 输出前m个
        if(m < n){
            for(int i=0; i<m; ++i){
                printf("%d ", nums[i]);
            }
            printf("\n");
        }
        else{
            for(int i=0; i<n; ++i){
                printf("%d ", nums[i]);
            }
            printf("\n");            
        }
        free(nums);
    }
}


int main()
{
    kuaisupaixu();

    return 0;
}
