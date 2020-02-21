#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef unsigned int uint;

/*
奇偶位互换
给定一个长度为偶数位的0,1字符串，请编程实现串的奇偶位互换。

输入
输入包含多组测试数据； 输入的第一行是一个整数C，表示有C测试数据；
接下来是C组测试数据，每组数据输入均为0,1字符串，保证串长为偶数位(串长<=50)。

输出 请为每组测试数据输出奇偶位互换后的结果；每组输出占一行。
*/

/*
Note:
    注意字符串末尾'\0'占位
    检查1 3 5 ...是否为'\0'，01交换 23交换 45交换
*/

void jiouweihuhuan()
{
    int T, num, temp;   
    char str[51];

    printf("input group num:");
    scanf("%d", &T);      
    while(T--){
        printf("input 0 1 string:");   
        scanf("%s", str);

        char temp;
        for(int i=1; str[i]!='\0'; i += 2){ // 01 10 10
            temp = str[i];                  // 10 01 01
            str[i] = str[i-1];
            str[i-1] = temp;
        }
        printf("Parity switching:");  
        printf("%s\n", str);
    }
}

int main()
{
    jiouweihuhuan();

    return 0;
}
