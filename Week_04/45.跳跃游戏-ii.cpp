/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int maxJumpPosition = 0;
        int end = 0;
        int n = nums.size() - 1;
        int now = 0;
        while(end < n) {
            maxJumpPosition = max(maxJumpPosition, now + nums[now]);
            if (now == end) {
                steps++;
                end = maxJumpPosition;
            }
            now++;
        }
        return steps;
    }
};
// @lc code=end

