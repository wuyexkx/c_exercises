// 思路
// 对于每个元素，找其左右两边第一个比它小的元素位置，位置作差 x 高度 = 包含当前元素组成最大的面积
// 在所有面积中求最大面积


// 暴力 最后一个超时
int largestRectangleArea(int* heights, int heightsSize){
    int maxarea = 0;
    for (int i=0; i<heightsSize; ++i) {
        int l = i-1, r = i+1;
        while (l >= 0 && heights[l] >= heights[i]) {            // 在左边找第一个比它小的
            l--;
        }

        while (r < heightsSize && heights[r] >= heights[i]) {   // 在右边找第一个比它小的
            r++;
        }
        int area = heights[i] * (r - l - 1);                    // 高 * 宽
        maxarea = area > maxarea ? area : maxarea; 
    }
    return maxarea;
}


// 单调栈
// 单调递增栈，存放索引
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int len = heights.size();
        vector<int> vl(len, -1), vr(len, len);  // 左边默认找到-1，右边默认找到len ,分别负责存放左 右比它小索引
        stack<int> sl, sr;                      // 

        for (int j=0, i=len-1; j<len; ++j, --i) {
            while (!sl.empty() && heights[i] < heights[sl.top()]) { // 注意stack存放的是索引，取出时比较的是值
                int k = sl.top();
                sl.pop();
                vl[k] = i;
            }
            sl.push(i);

            while (!sr.empty() && heights[j] < heights[sr.top()]) {
                int k = sr.top();
                sr.pop();
                vr[k] = j;
            }
            sr.push(j);
        }

        int maxarea = 0;
        for (int i=0; i<len; ++i) {
            int area = heights[i] * (vr[i] - vl[i] - 1);
            maxarea = area > maxarea ? area : maxarea;
        }

        return maxarea;
    }
};