#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
开门人和关门人
每天第一个到机房的人要把门打开，最后一个离开的人要把门关好。
现有一堆杂乱的机房签到、签离记录，请根据记录找出当天开门和关门的人。

输入
测试输入的第一行给出记录的总天数N ( > 0 )。
下面列出了N天的记录。 
每天的记录在第一行给出记录的条目数M ( > 0 )，下面是M行，每行的格式为
    证件号码    签到时间    签离时间   

其中时间按“小时:分钟:秒钟”（各占2位）给出，
证件号码是长度不超过15的字符串。

输出
对每一天的记录输出1行，即当天开门和关门人的证件号码，中间用1空格分隔。 
注意：在裁判的标准测试输入中，所有记录保证完整，
    每个人的签到时间在签离时间之前， 且没有多人同时签到或者签离的情况。
*/

/*
Note:
    1. 直接使用字符串比较，strcmp。时间格式固定依次比较
    2. 把时间计算成second再比较，
    身份证长度为15位，注意long long输入输出%lld 否则出错。或者%I64d
123456789012345 06:31:10 18:21:13
123456789012346 12:30:09 19:07:42
123456789012347 05:30:10 09:56:34   早
123456789012348 06:40:51 18:20:00
123456789012349 07:30:20 20:44:52   晚
123456789012340 16:30:17 18:20:00
输入：
    N                           (总天数)
    M                           (每天M条)
    证件号码 签到时间 签离时间   (<=15个字符)  (xx:xx:xx)  (xx:xx:xx)
    证件号码 签到时间 签离时间
            ...
    M
    证件号码 签到时间 签离时间
    证件号码 签到时间 签离时间 
            ...
输出：
    N                    (总天数)
    证件号码 证件号码    (开门人和关门人)
    证件号码 证件号码
        ...
*/

void kaimenrenheguanmenren()
{
    #define SECOND(h, m, s)     ( (h)*3600 + (m)*60 + (s) )
    uint N, M;
    unsigned long long num,
    earliest = SECOND(23, 59, 59),
    latest = SECOND(0, 0, 0),
    num_earliest, num_latest,
    date_in[3], date_out[3];

    scanf("%d", &N);
    while(N--){             // N天的数据
        scanf("%d", &M);
        while(M--){         // M条数据
            scanf("%lld %d:%d:%d %d:%d:%d", &num, 
            &date_in[0], &date_in[1], &date_in[2],
            &date_out[0], &date_out[1], &date_out[2]);
            long long in = SECOND(date_in[0], date_in[1], date_in[2]);
            long long out = SECOND(date_out[0], date_out[1], date_out[2]);

            if(in < earliest){
                earliest = in;
                num_earliest = num;
            }
            if(out > latest){
                latest = out;
                num_latest = num;
            }        
        }
        printf("1.earliest:%lld latest:%lld\n", num_earliest, num_latest);
    }
}

void kaimenrenheguanmenren1()
{
    uint N, M;
    char num[16], num_earliest[16], num_latest[16];
    char time_in[9], time_out[9], 
    time_earliest[9] = {"23:59:59"}, time_latest[9] = {"00:00:00"}; 
    
    scanf("%d", &N);
    while(N--){             // N天的数据
        scanf("%d", &M);
        while(M--){         // M条数据
            scanf("%s %s %s", num, time_in, time_out);
            if(strcmp(time_in, time_earliest) < 0){
                strcpy(time_earliest, time_in);
                strcpy(num_earliest, num);
            }
            if(strcmp(time_out, time_latest) > 0){
                strcpy(time_latest, time_out);
                strcpy(num_latest, num);
            }
        }
        printf("2.earliest:%s latest:%s\n", num_earliest, num_latest);
    }
}


int main()
{
    // kaimenrenheguanmenren();
    kaimenrenheguanmenren1();

    return 0;
}
