/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp;
        int n = s.size();
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(n);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j || i - j == 1) {
                    if (s[i] == s[j]) {
                        dp[j][i] = 1;
                        count++;
                    }
                    else {
                        dp[j][i] = 0;
                    }
                }
                else {
                    if (s[i] == s[j]) {
                        dp[j][i] = dp[j + 1][i - 1];
                        if (dp[j][i] == 1) {
                            count++;
                        }
                    }
                    else {
                        dp[j][i] = 0;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

