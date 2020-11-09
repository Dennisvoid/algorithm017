/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.resize(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int Min = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] < Min && dp[i - coins[j]] != -1) {
                    Min = dp[i - coins[j]];
                }
            }
            if (Min == INT_MAX) {
                dp[i] = -1;
            }
            else dp[i] = Min + 1;
        }
        return dp[amount];
    }
};
// @lc code=end

