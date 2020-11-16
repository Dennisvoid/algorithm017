/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> wordbank(wordList.begin(), wordList.end());
        if (wordbank.count(endWord) == 0) {
            return 0;
        }

        int level = 2;
        set<string> upTodown;  upTodown.insert(beginWord);
        set<string> downToup;  downToup.insert(endWord);
        vector<int> flags(wordList.size(), 0);

        while (!upTodown.empty()) {
            set<string> next;
            for (auto it : upTodown) {
                for (int i = 0; i < wordList.size(); i++) {
                    int diff = 0;
                    for (int j = 0; j < wordList[i].size(); j++) {
                        if (it[j] != wordList[i][j]) {
                            diff++;
                        }
                        if (diff > 1) {
                            break;
                        }
                    }
                    if (diff == 1) {
                        if (downToup.count(wordList[i]) > 0) return level;//最后肯定是访问到一个重复的，然后返回结果
                        if (flags[i] == 0) next.insert(wordList[i]);
                        flags[i] = 1;
                    }
                }
            }
            level++;
            upTodown = next;
            if (upTodown.size() > downToup.size()) swap(upTodown, downToup);
        }

        return 0;
    }
};
// @lc code=end

