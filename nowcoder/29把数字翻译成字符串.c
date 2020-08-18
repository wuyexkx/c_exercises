// 剑指 Offer 46. 把数字翻译成字符串

// 输入: 12258
// 输出: 5
// 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

// 对于 i 可以包含 i-1 和 只有 i 两种情况
// dp[i] ?= dp[i-1] + dp[i-2]   // str[i] str[i-1] <= "25"  (还要包括‘0’)
// dp[i] ?= dp[i-1]             // str[i] str[i-1] > "25"
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int step[3] = {1, 1, 1}; // d初始条件
        for (int i=1; i<s.size(); i++) {
            if (s[i-1] > '2' || (s[i] > '5' && s[i-1] == '2') || s[i-1] == '0') { // 两种情况
                step[2] = step[1];
            } else {
                step[2] = step[0] + step[1];
            }
            step[0] = step[1];
            step[1] = step[2];
        }
        return step[2];
    }
};