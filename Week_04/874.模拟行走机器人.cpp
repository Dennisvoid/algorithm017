/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 */

// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        int cur_x = 0;
        int cur_y = 0;
        vector<vector<int>> directions;
        vector<int> temp;
        temp.resize(2);
        for (int i = 0 ; i < 4; i++) {
            directions.push_back(temp);
        }
        directions[0][0] = 0; directions[0][1] = 1;
        directions[1][0] = 1; directions[1][1] = 0;
        directions[2][0] = 0; directions[2][1] = -1;
        directions[3][0] = -1; directions[3][1] = 0;
        int direction = 0;
        set<pair<int,int>> s;
        for (int i = 0; i < obstacles.size(); i++) {
            s.insert(pair(obstacles[i][0], obstacles[i][1]));
        }
        for (int i = 0; i < commands.size(); i++) {
            int length = commands[i];
            if (length == -1) {
                direction = (direction + 1) % 4;
            }
            else if (length == -2) {
                direction = (direction - 1 + 4) % 4;
            }
            else {
                for (int j = 1; j <= length; j++) {
                    if (s.count(pair(cur_x + directions[direction][0], cur_y + directions[direction][1])) > 0) {
                        break;
                    }
                    cur_x += directions[direction][0];
                    cur_y += directions[direction][1];
                    ans = max(ans, cur_x * cur_x + cur_y * cur_y);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

