#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
平方和与立方和
给定一段连续m到能n的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。

输入 输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。

输出 对于每组输入数据，输出一行，应包括两个整数x和y，
分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
你可以认为32位整数足以保存结果。
*/

/*
Note:
*/

void pingfangyulifanghe()
{
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF){  
        int even=0, odd=0;
        for(int i=m; i<=n; ++i){
            // 偶数
            if(i%2 == 0){
                even += i*i;
            }
            // 奇数
            else{
                odd += i*i*i;
            }
        }
        printf("%d %d\n", even, odd);
    }
}


int main()
{
    pingfangyulifanghe();

    return 0;
}
