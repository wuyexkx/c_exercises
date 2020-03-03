#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
第七部分
字符串替换
编写一个程序实现将字符串中的所有"you"替换成"we"

输入
输入包含多行数据 每行数据是一个字符串，长度不超过1000 数据以EOF结束

输出 对于输入的每一行，输出替换后的字符串
*/

/*
Note:
    1. 巧妙使用strlen, memcpy函数
    2. 骚操作，直接将缺失的那个替换成'\0'，而打印整个长度
*/

void zifuchuantihuan()
{
    int n, k;
    char strs[1001], you[4], temp;

    while(scanf("%s", strs) != EOF){          
        for(int i=0; i<strlen(strs)-2; ++i){
            memcpy(you, &strs[i], 3);
            if(strcmp(you, "you") == 0){
                strs[i] = 'w';
                strs[i+1] = 'e';
                memcpy(&strs[i+2], &strs[i+3], strlen(strs)-i-2);
            }
        } 
        printf("%s  %d\n", strs, strlen(strs));
    }
    // 骚操作，直接将缺失的那个替换成'\0'，而打印整个长度
    // length = strlen(s);
    // for(i=0;i<length-2;i++){  //这里处理很巧妙，直接赋值即可，真是高 
    //     if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u'){
    //         s[i]='w';
    //         s[i+1]='e';
    //         s[i+2]='\0';  //赋值为'\0'，是因为其他位置的字符不可能为'\0'   
    //     }        
    // }

    // for(i=0;i<length;i++){
    //     if(s[i]!='\0')
    //         printf("%c",s[i]);
    // }
}

int main()
{
    zifuchuantihuan();

    return 0;
}
