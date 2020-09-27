/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.size() == 0) return 0;
       int last_non_duplicate_index = 0;
       for (int i = 0; i <nums.size(); i++) {
           if (nums[i] != nums[last_non_duplicate_index]) {
               nums[++last_non_duplicate_index] = nums[i];
           }
       }
       return last_non_duplicate_index+1;
    }
};
// @lc code=end

