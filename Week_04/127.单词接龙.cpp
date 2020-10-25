/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int l;
        for (l = 0; l < wordList.size(); l++) {
            if (wordList[l] == endWord) {
                break;
            }
        }
        if (l == wordList.size()) return 0;
        for (auto it = wordList.begin(); it != wordList.end(); it++) {
            if (*it == beginWord) {
                wordList.erase(it);
                break;
            }
        }

        int level = 1;
        string temp;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();
                if (temp == endWord) {
                    return level;
                }
                for (auto it = wordList.begin(); it != wordList.end();) {
                    int diff = 0;
                    for (int k = 0; k < (*it).size(); k++) {
                        if ((*it)[k] != temp[k]) {
                            diff++;
                        }
                        if (diff > 1) {
                            break;
                        }
                    }
                    if (diff == 1) {
                        q.push(*it);
                        it = wordList.erase(it);
                    }
                    else it++;
                }
            }
            level++;
        }
        return 0;
    }
};
// @lc code=end

