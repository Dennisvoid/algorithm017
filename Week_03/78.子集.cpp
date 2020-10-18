/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(temp);
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> ans_temp;
            for (auto it:ans) {
                temp = it;
                temp.push_back(nums[i]);
                ans_temp.push_back(temp);
            }
            for (auto it:ans_temp) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};
// @lc code=end

