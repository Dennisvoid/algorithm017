/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size() + 1, vector<int>(s.size() + 2, INT_MAX));
        dp[0][0] = 1;
        for (int i = 1; i < s.size() + 1; i++) {
            dp[0][i] = 0;
        }
        dp[0][s.size() + 1] = 0;
        bool isStar = true;
        for (int i = 1; i < p.size() + 1; i++) {
            if (isStar && p[i - 1] == '*') {
                dp[i][0] = 1;
                dp[i][s.size() + 1] = 0;
            }
            else {
                dp[i][0] = 0;
                isStar = false;
            }
        }

        for (int i = 1; i < p.size() + 1; i++) {
            for (int j = 1; j < s.size() + 1; j++) {
                if (p[i - 1] == '*') {
                    if (j >= dp[i - 1][s.size() + 1]) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
                else {
                    if (p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else dp[i][j] = 0;
                }
                if (dp[i][j] == 1 && dp[i][s.size() + 1] == INT_MAX) dp[i][s.size() + 1] = j;
            }
        }

        /*for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout<<dp[i][j]<<"  ";
                if (j == dp[0].size() - 1) {
                    cout<<endl;
                }
            }
        }*/
        return dp[p.size()][s.size()] == 1;
    }
};
// @lc code=end

