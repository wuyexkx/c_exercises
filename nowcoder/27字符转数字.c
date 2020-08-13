
class Solution {
public:
    int strToInt(string str) {
    // #define INT_MAX (~0U >> 1)
    // #define INT_MIN (int)(-INT_MAX - 1)
        if (str.size() == 0) return 0;
        // 跳过空格
        int i = 0;
        while (str[i] == ' ') i++;
        // 判断符号
        int sign = 1;
        if (str[i] == '-') sign = -1;
        if (str[i] == '-' || str[i] == '+') i++;
        // 处理结果
        long long res = 0;
        for (; str[i] <= '9' && str[i] >= '0'; i++) {
           res = res * 10 + (str[i] - '0');
           if (sign == 1 && res > INT_MAX) return INT_MAX;
           if (sign == -1 && -res < INT_MIN) return INT_MIN;
        }    
        return sign * res;
    }
};
