#include <stdio.h>


// 题目： 976. 三角形的最大周长
// 一个数组，求组成三角形周长最大，返回周长
// 所有算法自己写，时间复杂度在n^2以内

// 用 快排 + 依次遍历 即可  nlogn + n
// 由大到小排序，三角形的边长关系 两边之和大于第三边，
// 取大数作为长边，紧跟的两个个数作为短边，如果能凑成三角形则周长最大，否则下一个数作为最大边
void qsort(int* nums, int size, int left, int right)
{
    if (left >= right) return;
    int l = left, r = right, pivot = nums[l];
    while (l < r) {
        while (l < r && nums[r] <= pivot) r--;
        if (l < r) nums[l] = nums[r];

        while (l < r && nums[l] > pivot) l++;
        if (l < r) nums[r] = nums[l];        
    }
    nums[l] = pivot;

    qsort(nums, size, left, l);
    qsort(nums, size, l + 1, right);
}

int lagestlen(int* nums, int size)
{
    // 由大到小排序
    qsort(nums, size, 0, size - 1);
    int maxlen = 0, curlen = 0;
    // 查找
    for (int i = 2; i < size; i++) {
        int a = nums[i - 2];
        int b = nums[i - 1];
        int c = nums[i];
        // 满足三角形的条件
        if (b + c > a) {
            curlen = a + b + c;
            maxlen = curlen > maxlen ? curlen : maxlen;
        }
    }
    return maxlen;
}

int main()
{
    int nums[] = {1,3,3,2};

    int len = sizeof(nums) / sizeof(*nums);

    return 0;
}