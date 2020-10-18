/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void DFS(vector<vector<int>>& ans, vector<int> temp, int cur, int n, int k) {
        if (temp.size() == k) { //boundary condition: output ans
            ans.push_back(temp);
            return;
        }
        if (cur == n + 1) return;// ending
        if (k - temp.size() > (n - cur + 1)) return; // cut branches

        temp.push_back(cur);
        DFS(ans, temp, cur + 1, n, k); //accept cur
        temp.pop_back();  //backtrack
        DFS(ans,temp,cur + 1, n, k); //don't accept cur
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        DFS(ans, temp, 1, n, k);
        return ans;
    }
};
// @lc code=end

