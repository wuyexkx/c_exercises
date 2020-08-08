// 连续子数组的最大和
// 剑指 Offer 42

// 最简单的动态规划
// 1 2 -1 3 -2
// 状态方程： dp[i] = dp[i-1] + nums[i]
// dp[i] 表示包含当前项及以前的最大值，需要由dp[i-1] 和 nums[i]得出，  *****
// 条件是 当前项 和 dp[i-1]比较
// ***** dp[i-1]是前i-1项的最大和 *****
int maxSubArray(int* nums, int numsSize){
#define max(a,b) (a > b ? a : b)

    int res = nums[0];
    int dpp = nums[0], dp;
    for (int i=1; i<numsSize; ++i) {
        if (dpp > 0) {
            dp = dpp + nums[i];
        } else {
            dp = max(dpp, nums[i]);
        }
        res = max(dp, res);
        dpp = dp;
    }
    return res;
}