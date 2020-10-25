/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long ans = x;
        while (ans * ans > x) {
            ans = 0.5 * (ans + x / ans);
        }
        return (int)ans;
    }
};
// @lc code=end

