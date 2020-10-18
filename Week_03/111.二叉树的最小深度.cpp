/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return 1;
        if (root->left != NULL && root->right == NULL) return minDepth(root->left) + 1;
        if (root->right != NULL && root->left == NULL) return minDepth(root->right) + 1;
        
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        return min(leftDepth, rightDepth) + 1;
    }
};
// @lc code=end

