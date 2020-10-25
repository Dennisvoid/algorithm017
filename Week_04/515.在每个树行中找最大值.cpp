/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int Max = INT_MIN;
        int cur_level_size = 1;
        int next_level_size = 0;
        TreeNode* p = NULL;
        while (!q.empty()) {
            p = q.front();
            q.pop();

            Max = max(Max, p->val);
            cur_level_size--;

            if (p->left != NULL) {
                q.push(p->left);
                next_level_size++;
            }
            if (p->right != NULL) {
                q.push(p->right);
                next_level_size++;
            }
            
            if (cur_level_size == 0) {
                ans.push_back(Max);
                Max = INT_MIN;
                cur_level_size = next_level_size;
                next_level_size = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

