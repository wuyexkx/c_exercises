// 34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] <= target) 
                l = m + 1;
            else
                r = m - 1;
        }
        if (r >= 0 && nums[r] != target) return {-1, -1};
        if (r < 0) return {-1, -1};

        int right = r;
        l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] < target) 
                r = m - 1;
            else 
                l = m + 1;
        }
        int left = l;
        return {left, right};
    }
};


// ========================= 解释，题解 ==============================
#include <iostream>
#include <vector>
using namespace std;

// 二分查找 target的左右边界
vector<int> search_range(const vector<int>& nums, int target)
{
    int l = 0, r = nums.size() - 1;
    // 寻找右边界  // l <= r 保证退出时 r 在 l 的左边
    while (l <= r) {        
        int m = (l + r) / 2;
        if (nums[m] <= target) l = m + 1; // <= 找右边界
        else r = m - 1;
    }
    // 要么找到了右边界在 l-1 or r， 要么没找到
    if ((r < 0) || (r >= 0 && nums[r] != target)) return {-1, -1};
    int right = r;

    // 寻找左边界，右边界存在 左一定存在 大不了相同
    l = 0, r = nums.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] < target) l = m + 1; //< 找右边界
        else r = m - 1; 
    }
    int left = l;

    return {left, right};    
}

int main()
{
    vector<int> nums{2,3,3,3,3,  6,7,12,12,17};
    int target = 12;

    vector<int>res =  search_range(nums, target);
    cout << res[0] << ", " << res[1] << endl;

    return 0;
}