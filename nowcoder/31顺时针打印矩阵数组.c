#include <iostream>
#include <vector>

using namespace std;


// 顺时针打印矩阵
void matrix_print(vector<vector<int>>& nums)
{
    int m = nums.size();
    int n = nums[0].size();
#define SIZE    (m * n)    
    int count = 0;
    int lr, ud, rl, du;
    for (int l = 0; l < (min(m, n) + 1) / 2; l++) {
        
        for (lr = l; lr <= n - 1 - l; lr++) {
            cout << nums[l][lr] << " ";
            count++;
        }
        if (count == SIZE) break;

        for (ud = l + 1; ud <= m - 1 - l; ud++) {
            cout << nums[ud][lr - 1] << " ";
            count++;
        }            
        if (count == SIZE) break;

        for (rl = lr - 1 - 1; rl >= l; rl--) {
            cout << nums[ud - 1][rl] << " ";
            count++;
        }
        if (count == SIZE) break;

        for (du = ud - 1 - 1; du >= l + 1; du--) {
            cout << nums[du][rl + 1] << " ";
            count++;
        }
    }
}


// 顺时针给矩阵赋值
void init_matrix(vector<vector<int>>& nums)
{
    int m = nums.size();
    int n = nums[0].size();
#define SIZE    (m * n)    
    int count = 0;
    int lr, ud, rl, du;
    for (int l = 0; l < (min(m, n) + 1) / 2; l++) {
        
        for (lr = l; lr <= n - 1 - l; lr++)
            nums[l][lr] = count++;
        if (count == SIZE) break;

        for (ud = l + 1; ud <= m - 1 - l; ud++)
            nums[ud][lr - 1] = count++;
        if (count == SIZE) break;

        for (rl = lr - 1 - 1; rl >= l; rl--)
            nums[ud - 1][rl] = count++;
        if (count == SIZE) break;

        for (du = ud - 1 - 1; du >= l + 1; du--)
            nums[du][rl + 1] = count++;
    }
}


int main()
{
    int M = 10;
    int N = 10;
    // vector<vector<int>> nums{{1,2,3,4}, {5,6,7,8}, {9,0,-1,-2}};
    // vector<vector<int>> nums{{1,2}, {3,4}, {5,6}, {7,8}, {9,0}};
    
    vector<vector<int>> nums(M, vector<int>(N));

    init_matrix(nums);
    
    matrix_print(nums);

    return 0;
}

// 力扣的题 剑指 Offer 29. 顺时针打印矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
#define SIZE    (m * n)        
        int count = 0;
        int lr, ud, rl, du;
        vector<int> res;
        for (int l = 0; l < (min(m, n) + 1) / 2; l++) {

            for (lr = l; lr <= n - 1 - l; lr++) {
                res.push_back(matrix[l][lr]);
                count++;
            }
            if (SIZE == count) break;
            for (ud = l + 1; ud <= m - 1 - l; ud++) {
                res.push_back(matrix[ud][lr - 1]);
                count++;
            }
            if (SIZE == count) break;
            for (rl = lr - 1 - 1; rl >= l; rl--) {
                res.push_back(matrix[ud - 1][rl]);
                count++;
            }
            if (SIZE == count) break;
                
            for (du = ud - 1 - 1; du >= l + 1; du--) {
                res.push_back(matrix[du][rl + 1]);
                count++;
            }
        }
        return res;
    }
};