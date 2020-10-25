/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        /*其实就是贪心算法*/
        map<int,int> m; 
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                m[5]++;
            }
            if (bills[i] == 10) {
                if (m[5] >= 1) {
                    m[5]--;
                    m[10]++;
                }
                else return false;
            }
            if (bills[i] == 20) {
                if (m[5] >= 1 && m[10] >= 1) {
                    m[5]--;
                    m[10]--;
                }
                else if (m[5] >= 3) {
                    m[5] -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};
// @lc code=end

