/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>& ans, string temp, int n, int left, int right) {
        if (left + right == 2 * n) {
            ans.push_back(temp);
            return;
        }

        //cut branches
        if (left < n) {
            temp.append(1,'(');
            dfs(ans, temp, n, left + 1, right);
            temp.erase(temp.size() - 1);
        }
        if (right < left) {
            temp.append(1,')');
            dfs(ans, temp, n, left, right + 1);
            temp.erase(temp.size() - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0) {
            return ans;
        }
        string temp;
        dfs(ans, temp, n, 0, 0);
        return ans;
    }
};
// @lc code=end

