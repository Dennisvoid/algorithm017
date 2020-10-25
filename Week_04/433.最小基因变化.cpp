/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> dict(bank.begin(), bank.end());
        if (dict.find(end) == dict.end()) {
            return -1;
        }
        string letters = "ATCG";
        int level = 1;
        queue<string> todo;
        todo.push(start);
        string temp;
        while (!todo.empty()) {
            int n = todo.size();
            for (int k = 0; k < n; k++) {//一次处理完一层
                temp = todo.front();
                todo.pop();
                for (int i = 0; i < temp.size(); i++) {
                    char to_be_changed = temp[i];
                    for (int j = 0; j < letters.size(); j++) {
                        temp[i] = letters[j];
                        if (temp == end) {
                            return level;
                        }
                        if (dict.find(temp) != dict.end()) {
                            todo.push(temp);
                            dict.erase(temp);
                        }
                    }    
                    temp[i] = to_be_changed;
                }
            }
            level++;
        }
        return -1;
    }
};
// @lc code=end

