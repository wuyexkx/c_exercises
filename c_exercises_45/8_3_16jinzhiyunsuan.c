#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
16进制的简单运算
现在给你一个16进制的加减法的表达式，要求用8进制输出表达式的结果。

输入
第一行输入一个正整数T（0<T<100000） 
接下来有T行，
每行输入一个字符串s（长度小于15)字符串中有两个数和一个加号或者一个减号，
且表达式合法并且所有运算的数都小于31位

输出 每个表达式输出占一行，输出表达式8进制的结果。
*/

/*
Note:
    直接在输入输出格式上控制，
        scanf("%x%c%x", &num1, &sign, &num2);
        result = num1 'x' num2;
        if(result < 0){
            result = -result;
            printf("-");
        }
        printf("%o\n", result);
*/

// 我的笨方法，真的够笨
void hexyunsuan()
{
    int T;
    char strs[16];
    scanf("%d", &T);
    while(T-- && scanf("%s", strs) != EOF){  

        int length = strlen(strs), index;
        int num1=0, num2=0, result=0;;
        // 找到符号所在位置
        for(int i=0; i<length; ++i){
            if(strs[i] == '+' || strs[i] == '-'){
                index = i;
                break;
            }
        }
        // 提取第一个数
        for(int i=0; i<index; ++i){
            if(strs[i] >= 'A' && strs[i] <= 'Z'){
                num1 += (strs[i] - 'A' + 10) * pow(16, index-i-1);
            }
            else if(strs[i] >= '0' && strs[i] <= '9'){
                num1 += (strs[i] - '0') * pow(16, index-i-1);
            }
        }
        // 提取第二个数
        for(int i=index+1; i<length; ++i){
            if(strs[i] >='A' && strs[i] <= 'Z'){
                num2 += (strs[i] - 'A' + 10) * pow(16, length-1-i);
            }
            else if(strs[i] >='0' && strs[i] <= '9'){
                num2 += (strs[i] - '0') * pow(16, length-1-i);
            }
        }
        // 根据符号运算
        if(strs[index] == '+'){
            result = num1 + num2;
        }
        else if(strs[index] == '-'){
            result = num1 - num2;
        }
        // 结果符号判断
        if(result < 0){
            result = -result;
            printf("-");
        }
        printf("%o\n", result);
    }
}


int main()
{
    hexyunsuan();

    return 0;
}
