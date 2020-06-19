
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // 传入为空时直接返回空的vector
        if (digits.size() == 0) return vector<string>(); 
        
        // 保存号码对应字符串到vstr
        vector<string> vns{"", "", "abc", "def", "ghi", "jkl", \
                            "mno", "pqrs", "tuv", "wxyz"};
        vector<string> vstr;
        for (auto s : digits) 
            vstr.push_back(vns[s - '0']);                         
        string trace;
        vector<string> res;
        bktc(vstr, 0, trace, res);

        return res; 
    }
    // 
    void bktc(vector<string>& vstr, int n, string& trace, vector<string>& res)
    {
        // 退出条件 当层数达到最大时退出
        if (trace.size() == vstr.size()) {
            res.push_back(trace);
            return;
        }
        // 候选 在0层是候选为a b c 在1层时候选为d e f
        for (int i=0; i<vstr[n].size(); ++i) { 
            // 若出现“aa” 或在 在trace中找不到当前层的这个元素 就要 执行 
            if ((n>0 && vstr[n] == vstr[n-1]) || \  
                (find(trace.begin(), trace.end(), vstr[n][i]) == trace.end())) 
                
                trace.insert(trace.end(), vstr[n][i]);
                bktc(vstr, trace.size(), trace, res);
                trace.erase(trace.end() - 1);
        }
    }
};