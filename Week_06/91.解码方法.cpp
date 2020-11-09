/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp;
        dp.resize(s.size());
        if (s[0] == '0') {
            dp[0] = 0;
        }
        else dp[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (i >= 1 && s[i - 1] != '0' && s[i - 1] - 48 < 3) {
                    dp[i] = (i >= 2 ? dp[i - 2] : 1);
                }
                else dp[i] = 0;
            }
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] - 48 < 7)) {
                if (i >= 2) {
                    dp[i] = dp[i - 1] + dp[i - 2];
                }
                else dp[i] = dp[i - 1] + 1;
            }
            else dp[i] = dp[i - 1];
        }
        for (int i = 0; i < dp.size(); i++) {
            cout<<dp[i]<<endl;
        }
        return dp[s.size() - 1];
    }
};
// @lc code=end

