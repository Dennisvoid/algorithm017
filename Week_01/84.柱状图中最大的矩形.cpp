/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        heights.insert(heights.begin(),0);
        int ans = 0;
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int top_index = s.top();
                s.pop();
                ans = max(ans, (i - s.top() - 1) * heights[top_index]);
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

