/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid = 0;
        int left = 0; int right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= nums[0] && (target > nums[mid] || target < nums[0])) {
                left = mid + 1;
            }
            else if (target > nums[mid] && target < nums[0]) {//发生旋转
                left = mid + 1;
            }
            else right = mid;
        }
        if (nums[left] == target) {
            return left;
        }
        else return -1;
    }
};
// @lc code=end

