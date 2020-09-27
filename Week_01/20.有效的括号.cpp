/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public: 
    bool isValid(string s) {
        if (s.size() == 0) return true;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {
                if (st.empty()) return false;
                char c = st.top();
                st.pop();
                switch(c) {
                    case '(' : {
                        if (s[i] != ')') return false;
                        break;
                    }
                    case '[' : {
                        if (s[i] != ']') return false;
                        break;
                    }
                    case '{' : {
                        if (s[i] != '}') return false;
                        break;
                    }
                }
            }
        }
        if (!st.empty()) return false;
        else return true;
    }
};
// @lc code=end

