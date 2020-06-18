
// 很棒的题解
// https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-xiang-jie-by-labuladong-2/
// result = []
// def backtrack(路径, 选择列表):
//     if 满足结束条件:
//         result.add(路径)
//         return
    
//     for 选择 in 选择列表:
//         做选择
//         backtrack(路径, 选择列表)
//         撤销选择

// 全排列 处理不重复数字 1 2 3
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> trace;
        backtrack(nums, trace, res);
        return res;
    }
    void backtrack(const vector<int>& nums, vector<int>& trace, vector<vector<int>>& res)
    {
        // 退出条件
        if (trace.size() == nums.size()) {
            res.push_back(trace);
            return;
        }
        // 选择路径
        for (auto n : nums) {
            if (std::find(trace.begin(), trace.end(), n) != trace.end()) // 在里边了
                continue;
            trace.push_back(n);             // 做出选择
            backtrack(nums, trace, res);
            trace.pop_back();               // 撤销选择
        }
    }
};
// 跟上面一样，多个visited
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        vector<int> trace;
        vector<vector<int>> res;
        backtrace(nums, trace, visited, res);
        return res;
    }
    void backtrace(vector<int>& nums, vector<int>& trace, \
                    vector<int>& visited, vector<vector<int>>& res)
    {
        if (trace.size() == nums.size()) {
            res.push_back(trace);
            return;
        }
        for (int i=0; i<nums.size(); ++i) {
            if (visited[i] != 0)
                continue;
            visited[i] = 1;
            trace.push_back(nums[i]);
            backtrace(nums, trace, visited, res);
            visited[i] = 0;
            trace.pop_back();
        }
    }
};


// 全排列 处理不重复字符串 abc
//  -1 被转换为无符号整数型别，string::npos 也就成了该型别的最大无符号值。 size_t
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        string trace;
        backtrace(s, trace, res);
        return res;
    }
    void backtrace(string& s, string& trace, vector<string>& res)
    {
        if (trace.size() == s.size()) {
            res.push_back(trace);
            return;
        }
        for (auto ss : s) {
            if (trace.find(ss) != string::npos) // 查找
                continue;
            trace.insert(trace.end(), ss);      // string末尾插入字符
            backtrace(s, trace, res);
            trace.erase(trace.end() - 1);       // string删除末尾字符
            // std::count(s.begin(), s.end(), ss)) string计数
        }
    }
};

// 全排列 处理重复的字符串 aab 使用unordered_set去重复
class Solution {
public:
    vector<string> permutation(string s) {
        unordered_set<string> uset;
        vector<bool> visited(s.size(), 0);
        string trace;
        backtrace(s, visited, trace, uset);
        return vector<string>(uset.begin(), uset.end());
    }
    void backtrace(string& s, vector<bool>& visited, string& trace,\
                                        unordered_set<string>& uset)
    { 
        if (trace.size() == s.size()) {
            uset.insert(trace);
            return;
        }
        for (int i=0; i<s.size(); ++i) { 
            if (visited[i] != 0)
                continue;
            visited[i] = 1;
            trace.insert(trace.end(), s[i]);    // string末尾插入字符
            backtrace(s, visited, trace, uset);
            trace.erase(trace.end() - 1);       // string删除末尾字符
            visited[i] = 0;                     // std::count(s.begin(), s.end(), ss)) string计数
        }
    }
};
