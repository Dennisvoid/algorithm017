/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int count;
    vector<int> parent;
    vector<int> rank;
    
    Solution() {
        count = 0;
    }

    void buildUnion(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    count++;
                }
                else parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (i != parent[i]) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            count--;
            if (rank[rootx] == rank[rooty]) rank[rootx]++;
        }
    }

    void DFS(vector<vector<char>>& grid, int i, int j) {
        int n = grid[0].size();
        if (i >= 1 && grid[i - 1][j] == '1' 
            && find(i * n + j) != find((i - 1) * n + j)) {
            unite(i * n + j, (i - 1) * n + j);
            DFS(grid, i - 1, j);
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == '1' 
            && find(i * n + j) != find((i + 1) * n + j)) {
            unite(i * n + j, (i + 1) * n + j);
            DFS(grid, i + 1, j);
        }
        if (j >= 1 && grid[i][j - 1] == '1' 
            && find(i * n + j) != find(i * n + j - 1)) {
            unite(i * n + j, i * n + j - 1);
            DFS(grid, i, j - 1);
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' 
            && find(i * n + j) != find(i * n + j + 1)) {
            unite(i * n + j, i * n + j + 1);
            DFS(grid, i, j + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        
        buildUnion(grid);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
};
// @lc code=end

