/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long int mid = 0;
        long int left = 0; long int right = num;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (mid * mid > num) {
                right = mid - 1;
            }
            else left = mid;
        }
        return left * left == num;
    }
};
// @lc code=end

