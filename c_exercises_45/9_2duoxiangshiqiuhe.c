#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
多项式求和
多项式的描述如下：

1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...

现在请你求出该多项式的前n项的和。

输入 输入数据由2行组成，首先是一个正整数m（m<100），
表示测试实例的个数，第二行包含m个正整数，
对于每一个整数(不妨设为n,n<1000），求该多项式的前n项的和。

输出 对于每个测试实例n，要求输出多项式前n项的和。
每个测试实例的输出占一行，结果保留2位小数。
*/

/*
Note:
*/

void duoxiangshiqiuhe()
{
    int m, n;
    scanf("%d", &m);
    while(m-- && scanf("%d", &n) != EOF){  
        // 
        float result = 0;
        for(int i=1; i<=n; ++i){
            if(i % 2 == 0){
                result -= 1/(i*1.0);
            }
            else{
                result += 1/(i*1.0);
            }
        }
        printf("%.2f ", result);
    }
}


int main()
{
    duoxiangshiqiuhe();

    return 0;
}
