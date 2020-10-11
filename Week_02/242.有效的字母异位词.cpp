/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char,int> m;
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            m[c1]++; m[c2]--;
        }
        if (m.empty()) return true;
        for (auto it:m) {
            if (it.second != 0) return false;
        }
        return true;
    }
};
// @lc code=end

