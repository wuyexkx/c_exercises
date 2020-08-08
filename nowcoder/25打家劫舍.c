// 198. 打家劫舍
// 不相邻的最大和 
// 递归的方法：
// 对于第i个元素存在两种情况：选 和 不选
//      如果选：opt[i] + opt[i-2] 如果不选：opt[i-1] 对于第i个的最优则是max(选的情况， 不选的情况)
// 退出条件：只有1个时返回nums[0], 两个时返回max
class Solution {
public:
    int rob(vector<int>& nums) {
        return rec_opt(nums, nums.size() - 1);
    }

    int rec_opt(vector<int>& nums, int i)
    {
        if (i < 0) return 0;
        else if (i == 0) 
            return nums[0];
        else if (i == 1)
            return max(nums[0], nums[1]); 
        else {
            int A = nums[i] + rec_opt(nums, i - 2);
            int B = rec_opt(nums, i - 1);
            return max(A, B);
        }
    }
};


// 上面递归重复计算了子序列 -- 重叠子问题。
// 用数组记录每个元素最优的结果，省去了重复计算
// 关键还是在于寻找迭代关系，初始状态，结束条件
class Solution {
public:
    int rob(vector<int>& nums) {
        return opt(nums);
    }

    int opt(vector<int>& nums)
    {
        int len = nums.size();
        if(len == 0) return 0;
        // 正文如下
        vector<int> opti(len, -1);          // opti用于记录第i个最优结果
        if (len > 0) 
            opti[0] = nums[0];
        if (len > 1) 
            opti[1] = max(nums[0], nums[1]);

        for (int i=2; i<len; ++i) {
            int A = nums[i] + opti[i - 2];
            int B = opti[i - 1];
            opti[i] = max(A, B);
        }
        return opti[len - 1];
    } 
};