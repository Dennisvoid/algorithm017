/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    //test is failed after reading the solution , it needs more practise!
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        int left = 0; int right = height.size() -1;
        int left_max = height[left]; 
        int right_max = height[right];
        int sum = 0;
        while (left < right) {
            if (left_max <= right_max) {
                left++;
                if (height[left] >= left_max) 
                    left_max = height[left];
                else 
                    sum += (left_max - height[left]);
            }
            else {
                right --;
                if (height[right] >= right_max) 
                    right_max = height[right];
                else 
                    sum += (right_max - height[right]);
            }
        }
        return sum;
    }
};
// @lc code=end

