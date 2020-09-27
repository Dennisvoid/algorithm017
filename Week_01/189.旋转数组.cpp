/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void reverse(vector<int>& nums, int start, int end) {
        int s = start; int e = end;
        while (s < e) {
            int temp = nums[e];
            nums[e] = nums[s];
            nums[s] = temp;
            s++; e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
       k = k % nums.size();
       reverse(nums, 0, nums.size()-1);
       reverse(nums, 0, k-1);
       reverse(nums, k, nums.size()-1);
    }
};
// @lc code=end

