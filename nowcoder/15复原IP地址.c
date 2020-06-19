
// 类似全排列
// 常规DFS 回溯
// 复杂在递归退出条件 和 和路径选择的规则
class Solution { 
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> trace;      // 路径
        bktc(s, 0, trace, res);    
        return res;
    }
    // 
    void bktc(string& s, int pos, vector<int>& trace, vector<string>& res)
    {
        // 退出条件，trace路径为4时需要检查退出条件了
        // 若路径为4后pos刚好到最后，需要保存结果
        // 若路径为4且pos<最后，则退出
        if (trace.size() == 4) {
            if (pos == s.size()) {
                string t = to_string(trace[0]) + ".";
                t += to_string(trace[1]) + ".";
                t += to_string(trace[2]) + ".";
                t += to_string(trace[3]);
                res.push_back(t);
            }
            return;
        }
        // 候选 和 筛选
        // 路径 + 选择列表（候选） + 选择规则（筛选）
        for (int i=1; i<4; ++i) { 
            if (pos + i > s.size())         // 若pos到了最后应该退出
                break;
            string ns = s.substr(pos, i);   // 取出pos后面的i个字符
            int num = atoi(ns.c_str());     // 转换成int
            if (num > 255 || ((ns.size() > 1) && ns[0] == '0')) // 抛弃 >255 或者 （首字符为0的数） 
                continue;
            trace.push_back(num);           // 操作
            bktc(s, pos + i, trace, res);
            trace.pop_back();               // 撤销
        }
    }
};