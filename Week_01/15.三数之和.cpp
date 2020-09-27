/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
       set<vector<int>> ret;
       if (nums.size() <= 2) return ans;
       sort(nums.begin(), nums.end(), less<int>());
       map<int,int> targets;
       for (int i = 0; i < nums.size(); i++) {
           targets.insert(map<int,int>::value_type(nums[i],i));
       }
       for (auto it:targets) {
           int target = -it.first;
           int index = it.second;
           int j = index + 1; int k = nums.size() - 1;
           while (j < k) {
               if (nums[j] + nums[k] < target) {
                   j++;
               }
               else if (nums[j] + nums[k] > target) {
                   k--;
               }
               else {
                   vector<int> temp;
                   if (-target > nums[k]) {
                       temp.push_back(nums[j]);
                       temp.push_back(nums[k]);
                       temp.push_back(-target);
                       ret.insert(temp);
                   }
                   else if (-target < nums[j]) {
                       temp.push_back(-target);
                       temp.push_back(nums[j]);
                       temp.push_back(nums[k]);
                       ret.insert(temp);
                   }
                   else {
                       temp.push_back(nums[j]);
                       temp.push_back(-target);
                       temp.push_back(nums[k]);
                       ret.insert(temp);
                   }
                   j++; k--;
               }
           }
       }
       for (auto it:ret) {
           ans.push_back(it);
       }
       return ans;
    }
};
// @lc code=end

