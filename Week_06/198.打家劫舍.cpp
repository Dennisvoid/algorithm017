/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp;
        int n = nums.size();
        dp.resize(n);

        //initiate
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], (i >= 2 ? dp[i - 2] : 0) + nums[i]);
        }

        return dp[n - 1];
    }
};
// @lc code=end

