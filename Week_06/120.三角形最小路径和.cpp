/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0 || triangle[0].size() == 0) {
            return 0;
        }
        vector<int> dp;
        dp.resize(triangle[triangle.size() - 1].size());
        //the dp vector has been simplified
        
        //initiate
        for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
            dp[i] = triangle[triangle.size() - 1][i];
        }

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
// @lc code=end

