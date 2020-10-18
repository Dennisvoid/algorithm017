/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int> temp, int cur, int len) {
        if (cur == len) { //boundary condition
            ans.push_back(temp);
            return;
        }
        for (int i = cur; i < len; i++) {
            swap(temp[i], temp[cur]);
            backtrack(ans, temp, cur + 1, len);
            swap(temp[i], temp[cur]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0, nums.size());
        return ans;
    }
};
// @lc code=end

