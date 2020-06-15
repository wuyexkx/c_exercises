
// 单调递减栈
// 栈低到栈顶依次减小（单调不增）
// 一次遍历就完成，每个元素的索引都需要入栈，后面的会依次跟top比较，大就pop然后索引求差
// 单调栈题目 496下一个更大元素  901股票价格跨度  42接雨水  84柱状图中最大矩形(11盛最多水的容器,不是单调栈)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> v(T.size(), 0);
        stack<int> stc;
        for (int i=0; i<T.size(); ++i) {
            while (!stc.empty() && T[i] > T[stc.top()]) {
                int k = stc.top();
                stc.pop();
                v[k] = i - k;
            }
            stc.push(i);
        }
        return v;
    }
};


// 暴力法通不过，依次比较索引相减
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> v(T.size());

        for (int i=0; i<T.size(); ++i) {
            for (int j=i+1; j<T.size(); ++j) 
            {
                if (T[j] > T[i]) {
                    v[i] = j - i;
                    break;
                } 
            }            
        }
        return v;
    }
};