/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //动态规划，尝试自底向上的编程

        //def the dp matrix 特殊处理
        vector<vector<int>> dp;
        dp.resize(grid.size() + 1);
        for (int i = 0; i <= grid.size(); i++) {
            dp[i].resize(grid[0].size() + 1);
            dp[i][grid[0].size()] = INT_MAX;
            if (i == grid.size()) {
                for (int j = 0; j <= grid[0].size(); j++) {
                    dp[i][j] = INT_MAX;
                }
            }
        }

        //initial
        dp[grid.size() - 1][grid[0].size()] = 0;//让dp[n - 1][n - 1]在for循环中正确完成初始化

        //自底向上
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

