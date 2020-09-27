/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int ans = min(height[0], height[height.size() - 1]) 
                  * (height.size() - 1);
        int j = 0; int k = height.size() - 1;
        while (j < k) {
            if (height[j] < height[k]) {
                j++;
                if (height[j] > height[j - 1]) {
                    ans = max(ans, min(height[j],height[k]) * (k - j));
                }
            }
            else {
                k--;
                if (height[k] > height[k + 1]) {
                    ans = max(ans, min(height[j],height[k]) * (k - j));
                }
            }
        }
        return ans;
    }
};
// @lc code=end

