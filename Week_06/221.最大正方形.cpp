/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp;
        int m = matrix.size();
        int n = 0;
        if (m > 0) n = matrix[0].size();
        if (n == 0) return 0;
        dp.resize(m);
        for (int i = 0; i < m; i++) {
            dp[i].resize(n);
        } 
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i] - 48;
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = matrix[i][0] - 48;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
            }
        }

        int max = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }
        }
        return max * max;
    }
};
// @lc code=end

