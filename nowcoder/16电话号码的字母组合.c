class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 传入为空时直接返回空的vector
        if (digits.size() == 0) return vector<string>(); 
        // 保存号码对应字符串到vstr
        vector<string> vns{"", "", "abc", "def", "ghi", "jkl", \
                            "mno", "pqrs", "tuv", "wxyz"};  
        vector<string> res;
        string trace;
        bktc(digits, vns, 0, trace, res);   
        return res;
    }

    void bktc(string& digits, vector<string>& vns, int level, string& trace, vector<string>& res)
    {
        // 退出条件 当层数达到最大时退出
        if (trace.size() == digits.size()) {
            res.push_back(trace);
            return;
        }
        // 候选 在0层是候选为a b c 在1层时候选为d e f
        for (int i=0; i<vns[digits[level] - '0'].size(); ++i) {
            trace.insert(trace.end(), vns[digits[level] - '0'][i]);
            bktc(digits, vns, level + 1, trace, res);
            trace.erase(trace.end() - 1);
        }
    }
};