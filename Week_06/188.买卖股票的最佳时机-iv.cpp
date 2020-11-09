/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int> {0, INT_MIN}));

        //dp[0][0][0] = 0;
        //dp[0][0][1] = INT_MIN;

        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            for (int j = k; j > 0; j--) {
                if (i == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i - 1][j][1] + prices[i], dp[i - 1][j][0]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[n - 1][k][0];
    }
};
// @lc code=end

