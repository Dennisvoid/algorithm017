/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
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

    void buildUnion(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    parent.push_back(i * n + j);
                    count++;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]); //路径压缩
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
            if (rank[rootx] == rank[rooty]) rank[rootx]++;
            count--;
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() == 0 || M[0].size() == 0) return 0; 
        int m = M.size();
        int n = M[0].size();
        buildUnion(M);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1 && i != j) {
                    unite(i * n + j, j * n + i);
                    unite(i * n + i, i * n + j);
                    unite(j * n + j, j * n + i);
                } 
            }
        }
        return count;
    }
};
// @lc code=end

