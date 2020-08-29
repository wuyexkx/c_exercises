#include <stdio.h>

// x = x & (x - 1) 能清除x最右边的1 
// 如： 
//      x为8 则 0000
//      x为7 则 0110


// 是否2的整数次幂
// 2的整数次幂有特点，最高非符号位为1，其他为0，1000 --> 0111 --> 0
int is2_intpow(int num)
{    
    if (num <= 0) 
        return 0;

    if ((num & (num - 1)) == 0) 
        return 1;
    else
        return 0;
}

// 统计1的个数
int count_bitis1(int num)
{
    int count = 0;
    while (num) {
        num = num & (num - 1);
        ++count;
    }
    return count;
}

// 统计两个数的位不相同的个数
int count_2num_not(int num1, int num2)
{
    long long tmp = num1 ^ num2;    // tmp = ~(num1 ^ num2) 变成 统计两个数相同位的个数， 同或 == 异或取反
    int count = 0;
    while (tmp) {
        tmp = tmp & (tmp - 1);
        ++count;
    }
    return count;
}


int main()
{
    int num1 = 0xFF;
    int num2 = 0x3;

    printf("%d ", is2_intpow(num1));
    printf("%d ", is2_intpow(num2));
    printf("%d ", count_bitis1(num1));
    printf("%d ", count_bitis1(num2));
    printf("%d ", count_2num_not(num1, num2));

    return 0;
}
