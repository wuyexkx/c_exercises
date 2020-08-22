// 连续子数组的最大和
// 剑指 Offer 42

// 最简单的动态规划
// 1 2 -1 3 -2
// 状态方程： dp[i] = dp[i-1] + nums[i]
// dp[i] 走到第i步时的连续最大和，需要由dp[i-1] 和 nums[i]得出，  *****
// 条件是    如果之前的dp[i-1]对当前项 有 正的贡献 则 应该加上当前项
//          如果之前的dp[i-1]对当前项没有正的贡献 则 还不如取当前项
// ***** dp[i-1]是前i-1项的最大和 *****
int maxSubArray(int* nums, int numsSize){
#define max(a,b) (a > b ? a : b)

    int res = nums[0];
    int dpp = nums[0], dp;
    for (int i=1; i<numsSize; ++i) {
        if (dpp > 0)
            dp = dpp + nums[i];
        else
            dp =nums[i];
        res = max(dp, res);
        dpp = dp;
    }
    return res;
}

// c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int step[2] = {nums[0]};
        for (int i=1; i<nums.size(); i++) {
            if (step[0] > 0) 
                step[1] = step[0] + nums[i];
            else 
                step[1] = nums[i];
            res = max(step[1], res);
            step[0] = step[1];
        }
        return res;
    }
};