/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

// @lc code=start
vector<pair<int, int>> goal_pos{pair(1, 2), pair(0, 0), pair(0, 1), pair(0, 2), pair(1, 0), pair(1, 1)};
vector<vector<int>> mov{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
vector<vector<int>> scores;
struct pos {
    string s;
    int dis;
    pos(string ss, int d) : s(ss), dis(d) {}
};

int get_scores(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += scores[s[i] - 48][i];
    }
    return sum;
}

bool operator < (const pos A, const pos B) {
    int sum_A = get_scores(A.s);
    int sum_B = get_scores(B.s);
    return sum_A + A.dis - (sum_B + B.dis) >= 0;
}

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        scores.resize(6);
        for (int i = 0; i < 6; i++) {
            scores[i].resize(6);
            for (int j = 0; j < 6; j++) {
                scores[i][j] = max(abs(goal_pos[i].first - (j / 3)), abs(goal_pos[i].second - (j % 3)));
            }
        }

        priority_queue<pos> pq;
        set<string> record;
        string str;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                str.append(1, board[i][j] + 48);
            }
        }
        pos temp(str, 0);
        pq.push(temp);

        while (!pq.empty()) {
            temp = pq.top();
            pq.pop();
            string s = temp.s;
            int dis = temp.dis;
            

            if (s == "123450") return dis;
            //if (record.count(s) != 0) continue;
            vector<string> neigh;
            neigh = neighbour(s);
            for (auto it : neigh) {
                if (record.count(it) == 0) {
                    temp.s = it;
                    temp.dis = dis + 1;
                    pq.push(temp);
                }
            }

            record.insert(s);
        }
        return -1;
    }
    
    vector<string> neighbour(string s) {
        int i;
        for (i = 0; s[i] != '0'; i++);
        vector<string> res;
        string temp;
        for (int j = 0; j < mov[i].size(); j++) {
            temp = s;
            temp[i] = temp[mov[i][j]];
            temp[mov[i][j]] = '0';
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

