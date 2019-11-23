#include <stdio.h>

// # 字符串化
// ## 连接符号

#define ABC(x) #x
#define CNT_(x)  cnt_##x // 在函数调用，变量前缀隐藏都用得到
 
int main()
{
    int cnt_1=6, cnt_2=7;

    printf(ABC(defghij\n)); // def\n被字符串化 "def\n"
    printf("cnt_1 = %d, cnt_2 = %d\n", CNT_(1), CNT_(2)); // 1/2分别连接cnt_得到变量cnt_1/2

// output:
    // defghij
    // cnt_1 = 6, cnt_2 = 7

    return 0;
}
