/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num == 1) return true;
        while (num % 2 == 0 || num % 3 == 0 || num % 5 ==0) {
            if (num % 2 == 0) num = num / 2;
            else if (num % 3 == 0) num = num / 3;
            else if (num % 5 == 0) num = num / 5;
            if (num == 1) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

