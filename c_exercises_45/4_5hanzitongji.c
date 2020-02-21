#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h> 
typedef unsigned int uint;

/*
汉字统计
统计给定文本文件中汉字的个数。

输入 输入文件首先包含一个整数n，表示测试实例的个数，然后是n段文本。
输出 对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。
*/

/*
Note:
    使用二个字节表示一个汉字，把一个汉字当成两个字符。
    每个字节的最高位是1，补码第一位是符号位,1 表示为负数,
        所以 汉字机内码的每个字节表示的十进制数都是负数。　　
*/

void hanzitongji()
{
    int T, num=0;
    char c;

    printf("input group num:");
    scanf("%d", &T);      
    while(T--){
        printf("input a string of Chinese characters:");

        while((c = getchar()) != '\n'){
            if(c < 0)
                ++num;
        } 

        printf("total: %d\n", num / 2);
        num = 0;
    }
}

int main()
{
    hanzitongji();

    return 0;
}
