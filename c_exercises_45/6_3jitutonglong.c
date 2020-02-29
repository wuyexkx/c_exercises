#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> 

typedef unsigned int uint;

/*
鸡兔同笼
已知鸡和兔的总数量为n,总腿数为m。
输入n和m,依次输出鸡和兔的数目，
如果无解，则输出“No answer”(不要引号)。

输入 第一行输入一个数据a,代表接下来共有几组数据，
在接下来的(a<10)、a行里，每行都有一个n和m.(0<m,n<100)

输出 输出鸡兔的个数，或者No answer
*/

/*
Note:
    x + y = n;
    2x + 4y = m;
*/

void jitutonglong()
{
    uint N, n, m;
    int num_chicken=0, num_rabbit=0;

    scanf("%d", &N);
    while(N--){            
        scanf("%d %d", &n, &m);
        for(int i=0; i<=m/2; ++i){
            for(int j=0; j<=m/4; ++j){
                if((2*i + 4*j) == m &&  (i + j) == n){
                    num_chicken = i;
                    num_rabbit = j;
                }
            }
        }
        if(num_chicken + num_rabbit)
            printf("chicken:%d rabbit:%d\n", num_chicken, num_rabbit);
        else
            printf("No answer\n");
    }
}

int main()
{
    jitutonglong();

    return 0;
}
