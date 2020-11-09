/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp;
        dp.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            dp[i].resize(m + 1);
        }

        //initiate
        for (int i = 0; i < m + 1; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i < n + 1; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (word2[i - 1] == word1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

