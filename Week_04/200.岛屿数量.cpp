/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    void findTheWholeIsland (vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0) return;
        if (i >= grid.size() || j >= grid[0].size()) {
            return;
        }

        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            findTheWholeIsland(grid, i - 1, j);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
            findTheWholeIsland(grid, i + 1, j);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            findTheWholeIsland(grid, i, j - 1);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') {
            findTheWholeIsland(grid, i, j + 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        if (grid.size() == 0) return ans;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    findTheWholeIsland(grid, i, j);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

