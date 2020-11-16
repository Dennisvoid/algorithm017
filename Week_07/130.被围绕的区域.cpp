/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start

class UnionFind {
private:
    int count;
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    };

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionn(int x, int y) {
        int rootx = find(x), rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rootx] = rooty;
            if (rank[rootx] == rank[rooty]) {
                rank[rooty]++;
            }
            count--;
        }
    }
};


class Solution {
public:
    int row, col;
    void solve(vector<vector<char>> &board) {
        row = board.size(), col = board.size() == 0 ? 0 : board[0].size();
        if (row == 0 || col == 0) {
            return;
        }

        UnionFind uf(row * col + 1);
        int dummy = row * col;

        auto node = [&](int i, int j) {
            return i * col + j;
        };

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] != 'O') continue;
                if ((i == 0 || i == row - 1 || j == 0 || j == col - 1)) {
                    uf.unionn(node(i, j), dummy);
                } else {
                    if (i - 1 > -1 && board[i - 1][j] == 'O')
                        uf.unionn(node(i, j), node(i - 1, j));
                    if (i + 1 < row && board[i + 1][j] == 'O')
                        uf.unionn(node(i, j), node(i + 1, j));
                    if (j - 1 > -1 && board[i][j - 1] == 'O')
                        uf.unionn(node(i, j), node(i, j - 1));
                    if (j + 1 < col && board[i][j + 1] == 'O')
                        uf.unionn(node(i, j), node(i, j + 1));
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && uf.find(node(i, j)) != uf.find(dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

