

// 双指针
// a    b    c    b    a
// ij  
// i    j
// i         j
//           i    j
//           i         j
// 用映射存储下标，如果找到相同元素的下标 > start
// 则：重复了。
// 记录每步后的长度。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int map[128];
        memset(map, -1, 128 * sizeof(int));

        int st = 0;
        int curlen = 0, maxlen = 0;
        for (int end=0; end<s.size(); ++end) {
            if (map[s[end]] >= st)
                st = map[s[end]] + 1;

            map[s[end]] = end;

            curlen = end - st + 1;
            maxlen = curlen > maxlen ? curlen : maxlen;  
        }
        return maxlen;
    }
};