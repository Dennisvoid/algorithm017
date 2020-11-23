/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
bool operator < (vector<int> A, vector<int> B) {
    return A[0] < B[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size(); i++) {
            if (i < intervals.size() - 1 && intervals[i][1] >= intervals[i + 1][0]) {
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

