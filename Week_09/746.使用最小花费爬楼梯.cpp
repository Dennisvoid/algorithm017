/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 0) return 0;
        if (cost.size() == 1) return cost[0];
        vector<vector<int>> dp(cost.size(), vector<int>(2, INT_MAX / 2));
        dp[0][0] = cost[0]; dp[1][1] = cost[1];
        for (int i = 1; i < cost.size(); i++) {
            dp[i][0] = min(dp[i - 1][0], (i >= 2 ? dp[i - 2][0] : INT_MAX)) + cost[i];
            if (i > 1) dp[i][1] = min(dp[i - 1][1], (i >= 2 ? dp[i - 2][1] : INT_MAX)) + cost[i];
        }
        return min(dp[cost.size() - 1][0], min(dp[cost.size() - 1][1], min(dp[cost.size() - 2][0], dp[cost.size() - 2][1])));
    }
};
// @lc code=end

