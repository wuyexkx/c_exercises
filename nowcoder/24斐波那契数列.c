#include <stdio.h>

// 动态规划
// 当前项 等于 前两项的和
// 条件是除了 1 2项为1
void fibnacci(int n)
{
    int dppp = 0, dpp = 1, dp = 1;
    for (int i=1; i<=n; i++) {
        if (i == 1 || i == 2) {
            printf("%d ", 1);
        } else {
            dp = dppp + dpp;
            printf("%d ", dp);
        }
        dppp = dpp;
        dpp = dp;
    }
}


int main()
{
    fibnacci(10);
    return 0;
}