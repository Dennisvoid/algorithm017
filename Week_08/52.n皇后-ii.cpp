/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        int ans = 0;
        DFS(ans, 0, 0, 0, 0, n);
        return ans;
    }

    void DFS(int& ans, int hang, int lie, int pie, int na, int n) {
        if (hang >= n) {
            ans++;
            return;
        }

        int available = (~(lie | pie | na)) & ((1 << n) - 1);
        while (available != 0) {
            int p = available & (-available);
            available = available & (available - 1);
            DFS(ans, hang + 1, lie | p, (pie | p) >> 1, (na | p) << 1, n);
        }
    }
};
// @lc code=end

