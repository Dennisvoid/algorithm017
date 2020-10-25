/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> wordId;
        vector<string> idWord;
        vector<vector<int>> edges;

        int id = 0;
        //build the mapping relationship between the id and the string
        for (const string& word:wordList) {
            if (wordId.count(word) == 0) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        //end case: termination
        if (wordId.count(endWord) == 0) {
            return {};
        }
        if (wordId.count(beginWord) == 0) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }

        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++) {
            for (int j = i + 1; j < idWord.size(); j++) {
                if (transformCheck(idWord[i], idWord[j]) == true) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int dest = wordId[endWord];
        vector<vector<string>> res;
        vector<int> now;
        queue<vector<int>> q;
        vector<int> cost(id, INT_MAX);
        q.push(vector<int> {wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty()) {
            now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> temp;
                for (int i = 0; i < now.size(); i++) {
                    temp.push_back(idWord[now[i]]);
                }
                res.push_back(temp);
            }
            else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> temp(now);
                        temp.push_back(to);
                        q.push(temp);
                    }
                }
            }
        }
        return res;
    }
    bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};
// @lc code=end

