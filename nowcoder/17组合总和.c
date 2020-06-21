

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> res;
        vector<int> trace;
        bktc(candidates, target, 0, trace, res);
        return res;
    }

    void bktc(vector<int>& cddt, int target, int start, vector<int>& trace, vector<vector<int>>& res)
    {
        // 退出条件是 target<=0； 若==0则需要保存结果
        if (target <= 0) {
            if (0 == target) 
                res.push_back(trace);
            return;
        }
        // 从start开始 不重复
        for (int i=start; i<cddt.size(); ++i) {
            trace.push_back(cddt[i]);
            bktc(cddt, target - cddt[i], i, trace, res); // 从i开始，递归包含自己，1111 4；从i+1开始 不会包含自己的和 13 4
            trace.pop_back();
        }
    }
};


// 在数组中 求 和为target的元素 组合
// 处理不重复使用元素的情况
// input:
    // [2,3,6,7]
    // 7
    // [2,3,5]
    // // 8
// output:
    // [[2,2,3],[7]]
    // [[2,3,3],[3,5]]
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> trace;
        bktc(candidates, target, 0, trace, res);
        return res;
    }
    void bktc(vector<int>& cddt, int target, int start, vector<int>& trace, vector<vector<int>>& res)
    {
        if (target <= 0) {
            if (target == 0)
                res.push_back(trace);
            return;
        }
        for (int i=start; i<cddt.size(); ++i) {
            trace.push_back(cddt[i]);
            bktc(cddt, target - cddt[i], i + 1, trace, res);
            trace.pop_back();
        }
    }
};