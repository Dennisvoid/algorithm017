/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans;
        if (nums.size() == 0) return ans;
        priority_queue<pair<int,int>> que;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (auto it:m) {
            que.push(pair(it.second, it.first));
        }
        for (int i = 0; i < k; i++) {
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};
// @lc code=end

