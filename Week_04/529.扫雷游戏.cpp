/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @lc code=start
class Solution {
public:
    void exposeAllRelatedEmptyBlocks(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0) return;
        if (i >= board.size() || j >= board[0].size()) return;

        board[i][j] = 'B';
        int bombCount = 0;
        for (int k = i - 1; k <= i + 1; k++) {
            for (int l = j - 1; l <= j + 1; l++) {
                if (k < 0 || l < 0 || k >= board.size() || l >= board[0].size()) {
                    continue;
                }
                if (board[k][l] == 'M') {
                    bombCount++;
                }
            }
        }
        if (bombCount != 0) {
            board[i][j] = char(bombCount + 48);
            return;
        }

        for (int k = i - 1; k <= i + 1; k++) {
            for (int l = j - 1; l <= j + 1; l++) {
                if (k < 0 || l < 0 || k >= board.size() || l >= board[0].size()) {
                    continue;
                }
                if (board[k][l] == 'E') {
                    exposeAllRelatedEmptyBlocks(board, k ,l);
                }
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int i = click[0];
        int j = click[1];
        if (board[i][j] == 'M') {
            board[i][j] = 'X';
            return board;
        }

        exposeAllRelatedEmptyBlocks(board, i, j);
        return board;
    }
};
// @lc code=end

