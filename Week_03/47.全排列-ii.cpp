/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& tag, vector<int>& nums, vector<int> temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (tag[i] == 1 || (i > 0 && nums[i - 1] == nums[i] && tag[i - 1] == 0)) {
                continue;//去重
            }
            temp.push_back(nums[i]);
            tag[i] = 1;
            backtrack(ans, tag, nums, temp);
            tag[i] = 0;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tag;
        tag.resize(nums.size());
        vector<int> temp;

        sort(nums.begin(), nums.end(), less<int>());
        backtrack(ans, tag, nums, temp);
        return ans;
    }
};
// @lc code=end

