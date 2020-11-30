/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size() || s.size() == 0 || t.size() == 0) {
            return 0;
        }
        vector<vector<long>> dp(t.size(), vector<long>(s.size(), 0));
        for (int i = 0; i < dp.size(); i++) {
            for (int j = i; j < dp[0].size(); j++) {
                if (i == j) {
                    if (i == 0) dp[i][j] = (t[i] == s[j]);
                    else dp[i][j] = (t[i] == s[j] && dp[i - 1][j - 1]);
                }
                else {
                    if (t[i] != s[j]) {
                        dp[i][j] = dp[i][j - 1];
                    }
                    else {
                        dp[i][j] = dp[i][j - 1] + (i > 0 ? dp[i - 1][j - 1] : 1);
                    }
                }
            }
        }
        return dp[t.size() - 1][s.size() - 1];
    }
};
// @lc code=end

