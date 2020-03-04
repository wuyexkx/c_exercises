#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
交换输出
输入n(n<100)个数，找出其中最小的数，
将它与最前面的数交换后输出这些数。
(如果这个第一个数就是最小的数，则保持原样输出，
如果最小的数有相同的按照前面的交换)

输入 输入数据有多组，每组占一行，每行的开始是一个整数n，
表示这个测试实例的数值的个数，跟着就是n个整数。
n=0表示输入的结束，不做处理。

输出 对于每组输入数据，输出交换后的数列，每组输出占一行。 
Ex: 3 6 4 9      --> 4 6 9
Ex: 5 8 6 3 3 5  --> 3 6 8 3 5
*/

/*
Note:
*/

void jiaohuanshuchu()
{
    int N;
    int nums[100];
    int length, temp;
    while(1){  
        scanf("%d", &N);
        if(N == 0) break;

        int min=pow(2, (sizeof(int) - 1) * 8 - 1);
        for(int i=0; i<N; ++i){
            scanf("%d", &nums[i]);
        }
        // 寻找最小的数
        for(int i=0; i<N; ++i){
            if(nums[i] < min){
                min = nums[i];
            }
        }
        // 寻找第一个最小值的位置
        for(int i=0; i<N; ++i){
            if(nums[i] == min){
                // 直接输出
                if(i == 0){
                    break;
                }
                // 若不是第一个，交换
                else{
                    temp = nums[i];
                    nums[i] = nums[0];
                    nums[0] = temp;
                }
            }
        }
        // 最后结果
        for(int i=0; i<N; ++i){
            printf("%d ", nums[i]);
        }
    }
}

int main()
{
    jiaohuanshuchu();

    return 0;
}
