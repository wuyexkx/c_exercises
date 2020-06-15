// 力扣20题. 有效的括号

// 用栈保存对应右括号，取出不等则继续保存，相等pop掉
class Solution {
public:
    bool isValid(string s) {

        if (s.size() == 0) return true; 
        if (s.size()%2 == 1) return false;

        unordered_map<char, char> map{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> stackc;
        stackc.push(map[s[0]]);
        for (int i=1; i<s.size(); ++i){
            if (!stackc.empty() && s[i] == stackc.top())
                stackc.pop();
            else stackc.push(map[s[i]]);
        }
        if (stackc.empty()) return true;

        return false;
    }
};
