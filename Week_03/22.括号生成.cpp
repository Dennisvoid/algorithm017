/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void generateParenthesisHelper(vector<string>& ans, int left, int right, int n, string temp) {
        if (left + right == 2 * n) {
            ans.push_back(temp);
            return;
        }
        //剪枝
        if (left < n) {
            generateParenthesisHelper(ans, left + 1, right, n, temp + '(');
        }
        if (left > right) {
            generateParenthesisHelper(ans, left, right + 1, n, temp + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        generateParenthesisHelper(ans, 0, 0, n, temp);
        return ans;
    }
};
// @lc code=end

