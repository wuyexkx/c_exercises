#include <stdio.h>

typedef unsigned int uint;

/*
第几天
给定一个日期，输出这个日期是该年的第几天。
YYYY-MM-DD
*/

/*
Note:
    同时满足以下条件：
    1、年份能被4整除；
    2、年份若是100的整数倍的话，需被400整除，否则是平年。
*/

void dijitian()
{
    printf("\nPlease enter date, such as 2008-8-8: ");
    uint year, month, day, all=0;
    while(scanf("%d-%d-%d", &year, &month, &day)){
        switch(month){
            case 1:  all = day; break;
            case 2:  all = 31 + day; break;
            case 3:  all = 28 + 31 + day; break;
            case 4:  all = 31 + 28 + 31 + day; break;
            case 5:  all = 30 + 31 + 28 + 31 + day; break;
            case 6:  all = 31 + 30 + 31 + 28 + 31 + day; break;
            case 7:  all = 30 + 31 + 30 + 31 + 28 + 31 + day; break;
            case 8:  all = 31 + 30 + 31 + 30 + 31 + 28 + 31 + day; break;
            case 9:  all = 31 + 31 + 30 + 31 + 30 + 31 + 28 + 31 + day; break;
            case 10: all = 30 + 31 + 31 + 30 + 31 + 30 + 31 + 28 + 31 + day; break;
            case 11: all = 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 28 + 31 + day; break;
            case 12: all = 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + 28 + 31 + day; break;
        }
        // 不是100的整数倍就要能被4整除，是100的整数倍就要能被400整除
        // (n%4 == 0 && n%100 != 0 || n%400 == 0) // 闰年
        if( ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) &&                                              
            (month > 2) ) 
            all += 1;

        printf("It's the %dth day of %d\n", all, year);
    }
}

// 第二种方法
void dijitian1()
{
    printf("\nPlease enter date, such as 2008-8-8: ");
    uint year, month, day; 
    int temp[12] = {31,28,31,30,31,30, 31,31,30,31,30,31}; 

    while(scanf("%d-%d-%d", &year, &month, &day)){
        // 记录总天数
        int all = 0;

        // 累加之前月份的天数
        for(int i=0; i<month-1; ++i){
            all += temp[i];
        }
        // 加本月天数
        all += day;
        // 如果是闰年 并且 月份大于2月 则加一天
        if( ((year%4 == 0 && year%100 !=0) || (year%400 == 0)) && // 闰年
            month > 2 )                                             // 大于2月的
            all += 1;
        
        printf("It's the %dth day of %d\n", all, year);
    }
}

int main()
{
    dijitian();

    return 0;
}
