
// 70. 爬楼梯
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 注意：给定 n 是一个正整数。

// 示例 1：

// 输入： 2
// 输出： 2
// 解释： 有两种方法可以爬到楼顶。
// 1.  1 阶 + 1 阶
// 2.  2 阶


// step[i] = step[i - 1] + step[i - 2]
// 解释：
// 假设现在在第5个台阶，问只走一次就到第5台阶的可能，
// 上一步处于第3台阶 或者 第4台阶，
// 那么到达第5台阶只跟第3和第4台阶有关，两种可能 +的关系
// step[5] = step[4] + step[3]
// 
class Solution {
public:
    int climbStairs(int n) {
        // if (n == 1) return 1;
        // if (n == 2) return 2;
        // if (n > 2) return climbStairs(n - 1) + climbStairs(n - 2);
        // return 0;

        int step[3] = {1, 2};
        if (n == 1) return step[0];
        else if (n == 2) return step[1];

        for (int i = 3; i <= n; i++) {
            step[2] = step[0] + step[1];
            step[0] = step[1];
            step[1] = step[2];
        }
        return step[2];
    }
};