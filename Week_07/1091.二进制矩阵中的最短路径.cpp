/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

// @lc code=start
int n;
int m;

struct pos {
    int x;
    int y;
    int dis;
    pos(int xx, int yy, int d) : x(xx), y(yy), dis(d) {}
   
};

bool operator < (const pos A, const pos B) {
    return max(m - 1 - A.x, n - 1 - A.y) + A.dis - (max(m - 1 - B.x, n - 1 - B.y) + B.dis) >= 0;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = (grid.size() > 0 ? grid[0].size() : 0);
        if (m == 0 || n == 0) return -1;
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }
        if (n == 1 && m == 1) {
            return 1;
        }

        priority_queue<pos> q;
        pos start(0, 0, 1);
        q.push(start);
        // 拥塞路径加入closeList
        vector<bool> closeList(n * m, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    closeList[i * m + j] = true;
                }
            }
        }
        // 不需要记录父节点，故openList只保存最小花费
        vector<int> openList(n * m, 0);
        openList[0] = 1;
        // 八个移动方向
        vector<vector<int>> mov {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, 0}, {0, -1}, {-1, -1}};
        while (!q.empty()) {
            pos cur = q.top();
            q.pop();
            int curIdx = cur.x * m + cur.y;
            closeList[curIdx] = true;
            for (int k = 0; k < 8; ++k) {
                int xx = cur.x + mov[k][0];
                int yy = cur.y + mov[k][1];
                int nextIdx = xx * m + yy;
                if (0 <= xx && xx < n && 0 <= yy && yy < m && !closeList[nextIdx]) {
                    if (xx == n - 1 && yy == m - 1) {
                        return openList[curIdx] + 1;
                    }
                    // 没有到走过改点或者当前的路线更优
                    if (openList[nextIdx] == 0 || openList[nextIdx] > openList[curIdx] + 1) {
                        openList[nextIdx] = openList[curIdx] + 1;
                        pos next(xx, yy, openList[curIdx] + 1);
                        q.push(next);
                    }//为什么这里还多一个判断条件：这说明启发式搜索与BFS还是有所不同，某种程度上是BFS加DFS的混合体
                }
            }
        }
        return -1;
    }
};
// @lc code=end

