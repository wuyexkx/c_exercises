
// 暴力法
// 借助unordered_map存储 nums2的元素和index
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        for (int i=0; i<nums2.size(); ++i) um.insert({nums2[i], i});
        vector<int> v(nums1.size(), -1);
        for (int i=0; i<nums1.size(); ++i) {                // 对于nums1中每个元素
            for (int j=um[nums1[i]]; j<nums2.size(); ++j) { // 从nums2中对应元素位置开始往后
                if (nums2[j] > nums1[i]) {
                    v[i] = nums2[j];
                    break;
                }
            }
        }
        return v;
    }
};


// 单调栈法
// 可以先不用管nums1，先把nums2中每个元素后面最近比大的用hashmap存储起来，然后用nums1去查找即可
// 这里栈存储的是元素
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        vector<int> v(nums1.size());

        // 先在nums2中用单调栈，把大的元素映射存起来
        stack<int> stck;
        for (int i=0; i<nums2.size(); ++i) {
            while (!stck.empty() && nums2[i] > stck.top()) {
                um.insert({stck.top(), nums2[i]});  // 值 和 大的值
                stck.pop();
            }
            stck.push(nums2[i]);
        }
        // 其余值应该映射存为-1 按题目要求
        while (!stck.empty()) {
            um.insert({stck.top(), -1});
            stck.pop();
        }
        // 按照nums1取出
        for (int i=0; i<nums1.size(); ++i) 
            v[i] = um[nums1[i]];

        return v;
    }
};