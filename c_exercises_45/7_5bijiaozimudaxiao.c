#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
比较字母大小
任意给出两个英文字母，比较它们的大小，
规定26个英文字母A,B,C.....Z依次从大到小。

输入 第一行输入T，表示有T组数据；接下来有T行，
每行有两个字母，以空格隔开；
输出 输出各组数据的比较结果，输出格式见样例输出；
（注意输出严格按照输入的顺序即输入是A B，输出时必须是A?B）
Ex:
    3
    A B
    A>B
    D T
    D>T
    V D
    V<D
    A A
    A=A
*/

/*
Note:
    输入缓冲区接收问题
    清除缓冲区

拓展：
"%[...]" 表示只提取与[]中相匹配的内容，碰到其他内容则终止提取；
"%[^...]"（注意异或符'^'）表示提取内容，碰到[]中相匹配的内容则终止提取； 
注意：这里的匹配是按字符进行的！
*/

void bijiaozimudaxiao()
{
    int T;
    char c1, c2, c;
    int length, temp;
    scanf("%d", &T);
    fflush(stdin);  // 清除缓冲区
    while(T-- && scanf("%c %c", &c1, &c2) != EOF){  
    fflush(stdin);  // 清除缓冲区

        if(c1 > c2){
            c = '<';
        }
        else if(c1 < c2){
            c = '>';
        }
        else{
            c = '=';
        }
        printf("%c%c%c\n", c1, c, c2);
    }
}

int main()
{
    bijiaozimudaxiao();

    return 0;
}
