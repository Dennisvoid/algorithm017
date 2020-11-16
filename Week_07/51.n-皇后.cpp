/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    set<int> shu;
    set<int> pie;
    set<int> na;
    vector<vector<string>> ans;
    set<pair<int, int>> chess;

    void dfs(int n, int i) {
        if (i == n) {
            ans.push_back(chessToAns(n));
            return;
        }

        for (int j = 0; j < n; j++) {
            if (shu.count(j) == 0 &&pie.count(i + j) == 0 
             && na.count(i - j) == 0) {
                chess.insert(pair(i, j));
                shu.insert(j);
                pie.insert(i + j);
                na.insert(i - j);

                dfs(n, i + 1);

                chess.erase(pair(i, j));
                shu.erase(j);
                pie.erase(i + j);
                na.erase(i - j);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return ans;
        dfs(n, 0);
        return ans;
    }

    vector<string> chessToAns(int n) {
        vector<string> res;
        res.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i].append(1, '.');
            }
        }
        for (auto it : chess) {
            int f = it.first;
            int s = it.second;
            res[f][s] = 'Q';
        }
        return res;
    }

};
// @lc code=end

