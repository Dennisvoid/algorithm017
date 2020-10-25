/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid_x = 0; int left_x = 0; int right_x = matrix.size() - 1;
        if (right_x < 0) return false;
        while (left_x < right_x) {
            mid_x = (left_x + right_x + 1) / 2;
            if (target >= matrix[mid_x][0]) {
                left_x = mid_x;
            }
            else right_x = mid_x - 1;
        }
        int mid_y = 0; int left_y = 0; int right_y = matrix[left_x].size() - 1;
        if (right_y < 0) return false;
        while (left_y < right_y) {
            mid_y = (left_y + right_y + 1) / 2;
            if (target >= matrix[left_x][mid_y]) {
                left_y = mid_y;
            }
            else right_y = mid_y - 1;
        }
        return target == matrix[left_x][left_y];
    }
};
// @lc code=end

