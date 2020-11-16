/*
 * @lc app=leetcode.cn id=433 lang=cpp
 *
 * [433] 最小基因变化
 */

// @lc code=start
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
       set<string> geneBank(bank.begin(), bank.end());
       if (geneBank.count(end) == 0) return -1;

       set<string> upTodown{start};
       set<string> downToup{end};
       vector<int> flags(bank.size(), 0);
       int level = 1;
       while (!upTodown.empty()) {
           set<string> next;
           for (auto it : upTodown) {
               for (int i = 0; i < bank.size(); i++) {
                    int diff = 0;
                    for (int j = 0; j < bank[i].size(); j++) {
                        if (bank[i][j] != it[j]) {
                            diff++;
                        } 
                        if (diff > 1) break;
                    }
                    if (diff == 1) {
                        if (downToup.count(bank[i]) > 0) return level;
                        if (flags[i] == 0) next.insert(bank[i]);
                        flags[i] = 1;
                    }
               }
           }
           upTodown = next;
           level++;
           if (upTodown.size() > downToup.size()) swap(upTodown, downToup);
       }
       return -1;
    }
};
// @lc code=end

