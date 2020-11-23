/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    //non-comparation
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        set<int> s(arr2.begin(), arr2.end());
        for (int i = 0; i < arr1.size(); i++) {
            m[arr1[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < m[arr2[i]]; j++) {
                ans.push_back(arr2[i]);
            }
        }
        for(auto it : m) {
            if (s.count(it.first) == 0) {
                for (int j = 0; j < it.second; j++) {
                    ans.push_back(it.first);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

