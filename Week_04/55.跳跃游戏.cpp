/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastCanJumpIndex = nums.size() - 1;
        int i;
        for (i = lastCanJumpIndex - 1; i >= 0; i--) {
            if (i + nums[i] >= lastCanJumpIndex) {
                lastCanJumpIndex = i;
            }
        }
        return lastCanJumpIndex == 0;
    }
};
// @lc code=end

