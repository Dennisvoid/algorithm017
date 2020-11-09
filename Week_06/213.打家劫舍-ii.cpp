/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        vector<int> dp1;
        vector<int> dp2;
        int n = nums.size();
        dp1.resize(n - 1);
        dp2.resize(n - 1);
        
        dp1[0] = nums[1];
        dp2[0] = nums[0];

        for (int i = 1; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 1], (i >= 2 ? dp1[i - 2] : 0) + nums[i + 1]);
        }
        for (int i = 1; i < n - 1; i++) {
            dp2[i] = max(dp2[i - 1], (i >= 2 ? dp2[i - 2] : 0) + nums[i]);
        }

        return max(dp1[n - 2], dp2[n - 2]);
    }
};
// @lc code=end

