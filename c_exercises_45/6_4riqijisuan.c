#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
日期计算
如题，输入一个日期，格式如：2010 10 24 ，
判断这一天是这一年中的第几天。

输入 第一行输入一个数N（0<N<=100）,表示有N组测试数据。
后面的N行输入多组输入数据，每行的输入数据都是一个按题目要求格式输入的日期。
输出 每组输入数据的输出占一行，输出判断出的天数n
*/

/*
Note:
*/

void riqijisuan()
{
    uint N, year, month, day;
    uint m_days[12] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

    scanf("%d", &N);
    while(N--){            
        scanf("%d %d %d", &year, &month, &day);

        uint results = 0;
        for(int i=0; i<month-1; ++i){
            results += m_days[i];
        }   
        results += day;  
        // 是否瑞年
        if( (month > 2) && ((year%400==0) || (year%4==0 && year%100!=0)) )
            ++results;
            
        printf("%d\n", results);
    }
}

int main()
{
    riqijisuan();

    return 0;
}
