/*
 * @lc app=leetcode.cn id=818 lang=cpp
 *
 * [818] 赛车
 */

// @lc code=start
/*class Solution {
public:
    int quick_log(int num) {
        if (num == 1) return 0;
        int count = -1;
        int temp = 1;
        while (temp <= num) {
            temp = temp << 1;
            count++;
        }
        return count;
    }
    int dfs(int begin, int target, int dir) {
        if (target == begin) return 0;
        int expr = quick_log(abs(target - begin) + 1);
        if (target > begin && (begin + pow(2, expr) - 1) == target) {
            return expr + (dir == -1);
        }
        if (target < begin && (begin - pow(2, expr) + 1) == target) {
            return expr + (dir == 1);
        }
        
        if (target > begin)
            return min(expr + (dir == -1 ? 1 : 2) + dfs(begin + pow(2, expr) - 1, target, 1), expr + (dir == -1 ? INT_MAX / 2 : 1) + dfs(begin + pow(2, expr + 1) - 1, target, 1));
        else 
            return min(expr + (dir == 1 ? 1 : 2) + dfs(begin - pow(2, expr) + 1, target, -1), expr + (dir == 1 ? INT_MAX / 2 : 1) + dfs(begin - pow(2, expr + 1) + 1, target, -1));
    }
    int racecar(int target) {
        return dfs(0, target, 1);
    }
};*/
class Solution {
public:
    int dp[10001];
    int racecar(int target) {
        if (dp[target] > 0) return dp[target];
        int n = floor(log2(target)) + 1;
        if (target + 1 == (1<<n)) {
            dp[target] = n;
        } else {
            // n个A到达2^n-1位置，然后R反向，走完剩余
            dp[target] = n + 1 + racecar((1<<n) - 1 - target);
            // n-1个A到达2^(n-1)-1位置，然后R反向走m个A，再R反向，走完剩余
            // m取值遍历[0, n-1)
            for (int m = 0; m < n-1; ++m) {
                dp[target] = std::min(dp[target], n + m + 1 + racecar(target - (1<<(n - 1)) + (1<<m)));
            }
        }
        return dp[target];
    }
};

// @lc code=end

