
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count1(26, 0);  // 用于计数
        vector<int> count2(26, 0);  // 

        for (auto s1 : s)
            count1[s1 - 'a']++;
        for (auto t1 : t)
            count2[t1 - 'a']++;

        int i = 0;
        for (auto v : count1) {
            if (v != count2[i++])
                return false;
        }
        return true;
    }
};