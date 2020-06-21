// 超出时间限制 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        bktc(nums, target, res);
        return res;
    }
    void bktc(vector<int>& nums, int target, int& res)
    {
        
        if (target < 0) {
            return;
        }
        if (target == 0) {
            ++res;
            return;
        }        

        for (int i=0; i<nums.size(); ++i) 
            bktc(nums, target - nums[i], res);
    }
};