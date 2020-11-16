/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> heng;
        vector<set<int>> shu;
        vector<set<int>> ge;
        heng.resize(9); shu.resize(9); ge.resize(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (heng[i].count(board[i][j] - 48) == 0) {
                        heng[i].insert(board[i][j] - 48);
                    }
                    else return false;

                    if (shu[j].count(board[i][j] - 48) == 0) {
                        shu[j].insert(board[i][j] - 48);
                    }
                    else return false;

                    if (ge[3 * (i / 3) + j / 3].count(board[i][j] - 48) == 0) {
                        ge[3 * (i / 3) + j / 3].insert(board[i][j] - 48);
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

