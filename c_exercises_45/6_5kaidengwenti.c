#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
开灯问题
有n盏灯，编号为1~n，第1个人把所有灯打开，
第2个人按下所有编号为2 的倍数的开关（这些灯将被关掉），
第3 个人按下所有编号为3的倍数的开关
（其中关掉的灯将被打开，开着的灯将被关闭），依此类推。
一共有k个人，问最后有哪些灯开着？
输入：n和k，输出开着的灯编号。k≤n≤1000

输入 输入一组数据：n和k
输出 输出开着的灯编号
*/

/*
Note:
*/

void kaidengwenti()
{
    int n, k;

    while(scanf("%d %d", &n, &k) != EOF){            
        int light[n+1];
        for(int i=0; i<=n; ++i){
            light[i] = -1;
        }

        for(int i=1; i<=k; ++i){
            for(int j=1; j<=n; ++j){
                if(j%i == 0){
                    light[j] = -light[j];
                }
            }
        }        

        for(int i=1; i<=n; ++i){
            if(light[i] == 1)
                printf("%d ", i);
        }
    }
}

int main()
{
    kaidengwenti();

    return 0;
}
