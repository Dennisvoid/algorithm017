/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid = 0; int left = 0; int right = nums.size() - 1;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= nums[0] && nums[mid] >= nums[right]) {
                left = mid + 1;
            }
            else right = mid;
        }
        return nums[left];
    }
};
// @lc code=end

