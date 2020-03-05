#include <stdio.h>
#include <stdlib.h>
typedef unsigned int uint;

/*
数值统计
统计给定的n个数中，负数、零和正数的个数。

输入 输入数据有多组，每组占一行，每行的第一个数是整数n（n<100），
     表示需要统计的数值的个数，然后是n个实数；如果n=0，则表示输入结束，该行不做处理。
输出 对于每组输入数据，输出一行a,b和c，分别表示给定的数据中负数、零和正数的个数。
*/


/*
Note:
    不用动态分配的内存也能实现，scanf对于数字，本身就是输入一个执行一个。
    for(i=0;i<n;i++){
        scanf("%lf",&number);
            
        if(number<0)
            a++;
                
        else if(number==0)
            b++;
                
        else
            c++;
    }
*/

void shuzhitongji()
{
    uint num;             
    while(1){
        uint num_n=0, num_z=0, num_p=0;

        printf("\nPlease enter the num, num1 num2 ..., such as 3 -1 0 1: ");    
        scanf("%d", &num);
        if(num == 0) return;

        int *nums = (int *)malloc(sizeof(int)*num);
        for(uint i=0; i<num; ++i){
            scanf("%d", &nums[i]);
        }

        for(uint i=0; i<num; ++i){
            if(nums[i] > 0)
                ++num_p;
            else if(nums[i] < 0)
                ++num_n;
            else
                ++num_z;
        }
        printf( "\nnums of Negative Zero Positive: %d %d %d\n", num_n, num_z, num_p);
        free(nums);
    }
}

int main()
{
    shuzhitongji();

    return 0;
}
