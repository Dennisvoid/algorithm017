/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> temp1(mid - start + 1, 0);
        vector<int> temp2(end - mid, 0);
        for (int i = 0; i < temp1.size(); i++) {
            temp1[i] = nums[start + i];
        }
        for (int i = 0; i < temp2.size(); i++) {
            temp2[i] = nums[mid + 1 + i];
        }
        int i = 0; int j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= temp2.size() || (i < temp1.size() && temp1[i] <= temp2[j])) {
                nums[k] = temp1[i++];
            }
            else {
                nums[k] = temp2[j++];
            }
        }
    }

    int merge_and_count(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = start + (end - start) / 2;
            int count = merge_and_count(nums, start, mid) + merge_and_count(nums, mid + 1, end);
            int j = mid + 1;
            for (int i = start; i <= mid; i++) {
                while (j <= end && nums[i] > 2LL * nums[j]) {
                    j++;
                }
                count += j - (mid + 1);
            }
            merge(nums, start, mid, end);
            return count;
        }
        else return 0;
    }
    int reversePairs(vector<int>& nums) {
        return merge_and_count(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

