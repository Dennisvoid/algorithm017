/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i;
        for (i = 0; i < g.size(); i++) {
            bool is_content = false;
            for (auto it = s.begin(); it != s.end(); it++) {
                if (*it >= g[i]) {
                    is_content = true;
                    s.erase(it);
                    break;
                }
            }
            if (is_content == false) {
                break;
            }
        }
        return i;
    }
};
// @lc code=end

