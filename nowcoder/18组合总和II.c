// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用一次。

// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

// 示例 2:
// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]

// 决策树的样子 需要去除重复
// 因为C++没有为vector定义的默认hash方法,unordered_set<vector<int>, HashFunc>, 
// 所以要么先排序然后转string再hashset
//  要么自定义hash
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> trace;
        unordered_set<string> uset; // 存储排序后的vector元素 "112"
        bktc(candidates, target, 0, trace, res, uset);
        return res;
    }
    void bktc(vector<int>& cddt, int target, int start, vector<int>& trace, vector<vector<int>>& res, unordered_set<string>& uset)
    {
        if (target <= 0) {
            if (target == 0) {
                vector<int> t(trace);                
                sort(t.begin(), t.end());
                string str;
                for(int i=0; i<t.size(); ++i)
                { str += to_string(t[i]); }               
                if (uset.find(str) == uset.end()) {
                    uset.insert(str);
                    res.push_back(t);
                }
            }
            return;
        }
        for (int i=start; i<cddt.size(); ++i) {
            trace.push_back(cddt[i]);
            bktc(cddt, target - cddt[i], i + 1, trace, res, uset);
            trace.pop_back();
        }
    }
};