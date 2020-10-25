/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    void greedy_DFS(int coin_index, int& ans, int count, vector<int>& coins, int amount) {
        if (amount == 0) { //terminator
            ans = min(ans, count);
            return;
        }
        if (coin_index == coins.size()) return;

        for (int k = amount / coins[coin_index]; k >= 0 && (k + count) < ans; k--) {
            greedy_DFS(coin_index + 1, ans, count + k, coins, amount - k * coins[coin_index]);
        }//process + drill_down + backtrace + cut branches
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = INT_MAX;
        if (coins.size() == 0) return -1;
        if (amount == 0) return 0;
        sort(coins.rbegin(), coins.rend());
        greedy_DFS(0, ans, 0, coins, amount);
        if (ans == INT_MAX) ans = -1;
        return ans;
    }
};
// @lc code=end

