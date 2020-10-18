/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    void buildTreeHelper(vector<int>& preorder, vector<int>& inorder, TreeNode* root, int cur, int left, int right) {
        if (root == NULL) return;
        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if(inorder[i] == root->val) {
                index = i;
                break;
            }
        }
        int left_tree_size = index - left;
        int right_tree_size = right - index;
        if (cur + 1 != preorder.size() && left_tree_size > 0) {
            root->left = new TreeNode(preorder[cur + 1]);
            buildTreeHelper(preorder, inorder, root->left, cur + 1, left, index - 1);
        }
        if (cur + left_tree_size + 1 < preorder.size() && right_tree_size > 0) {
            root->right = new TreeNode(preorder[cur + left_tree_size + 1]);
            buildTreeHelper(preorder, inorder, root->right, cur + left_tree_size + 1, index + 1, right);
        }    
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        buildTreeHelper(preorder, inorder, root, 0, 0, preorder.size() - 1);
        return root;
    }
};
// @lc code=end

