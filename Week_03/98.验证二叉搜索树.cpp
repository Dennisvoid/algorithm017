/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBstHelper(TreeNode* root, long left_bound, long right_bound) {
        if (root == NULL) return true;
        if ((root->val < right_bound && root->val > left_bound)
            && isValidBstHelper(root->left, left_bound, root->val)
            && isValidBstHelper(root->right, root->val, right_bound)) {
            return true;
        }
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        long left_bound = -2147483648 - 1;
        long right_bound = 2147483648 + 1;
        return isValidBstHelper(root, left_bound, right_bound);
    }
};
// @lc code=end

