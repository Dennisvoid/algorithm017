/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        vector<int> dp;
        dp.resize(s.size());
        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(') {
                dp[i] = 0;
            }
            else {
                if (s[i - 1] == ')') {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                    }
                    else dp[i] = 0;
                }
                else dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
            }
        }
        int max = 0;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }

};
// @lc code=end

