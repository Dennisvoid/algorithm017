/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
       map<int,int> m;
       vector<int> ans;
       for (int i = 0; i < nums.size(); i++) {
           m.insert(map<int,int>::value_type(nums[i],i));
           if (m.count(target - nums[i]) > 0 && m[target - nums[i]] != i) {
               ans.push_back(i);
               ans.push_back(m[target - nums[i]]);
               break;
           }
       }
       return ans;
    }
};
// @lc code=end

