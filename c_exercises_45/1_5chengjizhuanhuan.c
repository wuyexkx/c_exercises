#include <stdio.h>

typedef unsigned int uint;

/*
成绩转换
输入一个百分制的成绩M，将其转换成对应的等级，
具体转换规则如下： 
    90~100为A; 80~89为B; 70~79为C; 60~69为D; 0~59为E;
*/


/*
Note:

*/

void chengjizhuanhuan()
{
    uint score;
    char c;

    printf("please enter a score (0~100): ");
    while(scanf("%d", &score)){
        if(score >= 90)
            c = 'A';
        else if(score >= 80)
            c = 'B';
        else if(score >= 70)
            c = 'C';
        else if(score >= 60)
            c = 'D';
        else if(score >= 0)
            c = 'E';

        printf("degree: %c\n", c);
    }
}

int main()
{
    chengjizhuanhuan();

    return 0;
}
