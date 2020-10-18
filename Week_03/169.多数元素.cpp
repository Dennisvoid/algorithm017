/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int count_on_range(vector<int>& nums, int num, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }
    int majorityElementHelper(vector<int>& nums, int left, int right) {
        if (left == right) { //boudary case
            return nums[left];
        }

        //process

        //drill down
        int ans1 = majorityElementHelper(nums, left, left + (right - left) / 2);
        int ans2 = majorityElementHelper(nums, left + (right - left) / 2 + 1, right);

        if (ans1 == ans2) return ans1;
        else {
            if (count_on_range(nums, ans1, left, left + (right - left) / 2) >
                count_on_range(nums, ans2, left + (right - left) / 2 + 1, right)) {
                return ans1;
            }
            else return ans2;
        }
        //reverse back
    }
    int majorityElement(vector<int>& nums) {
        return majorityElementHelper(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

