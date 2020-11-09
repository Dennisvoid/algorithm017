/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<long>> dp;
        dp.resize(grid.size() + 1);
        for (int i = 0; i <= grid.size(); i++) {
            dp[i].resize(grid[0].size() + 1);
            dp[i][grid[0].size()] = 0;
            if (i == grid.size()) {
                for (int j = 0; j <= grid[0].size(); j++) {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else dp[i][j] = -1;
            }
        }
        dp[grid.size() - 1][grid[0].size()] = 1;

        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if (dp[i][j] != 0)
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

