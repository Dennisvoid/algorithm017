/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */ 

// @lc code=start
class Solution {
public:
    map<int,int> m;
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (m.count(n) != 0) {
            return m[n];
        }
        int ans = climbStairs(n - 1) + climbStairs(n - 2);
        m[n] = ans;
        return ans;
    }
};
// @lc code=end

