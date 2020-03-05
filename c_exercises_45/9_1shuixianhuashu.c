#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
水仙花数
春天是鲜花的季节，水仙花就是其中最迷人的代表，
数学上有个水仙花数，他是这样定义的：

“水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，
比如：153=1^3+5^3+3^3。

现在要求输出所有在m和n范围内的水仙花数。

输入 输入数据有多组，每组占一行，包括两个整数m和n（100<=m<=n<=999）。
输出
对于每个测试实例，要求输出所有在给定范围内的水仙花数，
就是说，输出的水仙花数必须大于等于m,并且小于等于n，
如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开; 
如果给定的范围内不存在水仙花数，则输出no; 每个测试实例的输出占一行。
*/

/*
Note:
    拆分各位：
            while(num)
            {
                digits[k] = num % 10;
                num /= 10;
                ++k;
            }
*/

void shuixianhuashu()
{
    int m, n;
    int digits[3];
    while(scanf("%d%d", &m, &n) != EOF){  
        for(int i=m; i<=n; ++i){
            // 取出各位，0个位，1十位，2百位
            int k=0, num = i, result=0;
            while(num)
            {
                digits[k] = num % 10;
                num /= 10;
                ++k;
            }
            // 立方累加
            for(int j=0; j<3; ++j){
                result += pow(digits[j], 3);
            }
            // 判断
            if(result == i){
                printf("%d ", i);
            }
        }
    }
}


int main()
{
    shuixianhuashu();

    return 0;
}
