/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

        vector<vector<int>> heng(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> shu(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') {
                    heng[i][j] = 0;
                    shu[i][j] = 0;
                }
                else {
                    heng[i][j] = j > 0 ? (heng[i][j - 1] + 1) : 1;
                    shu[i][j] = i > 0 ? (shu[i - 1][j] + 1) : 1;
                    int heng_min = heng[i][j];
                    for (int k = 1; k <= shu[i][j]; k++) {
                        heng_min = min(heng_min, heng[i - k + 1][j]);
                        ans = max(ans, heng_min * k);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

