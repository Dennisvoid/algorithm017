/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    bool DFS(TreeNode*& ans, TreeNode* root, TreeNode* p, TreeNode* q) {//其子树是否含p或q
        if (root == NULL) return false;
        bool flag1 = DFS(ans, root->left, p, q);
        bool flag2 = DFS(ans, root->right, p, q);
        if ((flag1 && flag2) || ((root == p || root == q) && (flag1 || flag2))) {
            ans = root;
        }
        return (flag1 || flag2) || (root == p || root == q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        DFS(ans, root, p, q);
        return ans;
    }
};
// @lc code=end

