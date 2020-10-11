/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        TreeNode* p = NULL;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            if (p->right != NULL) st.push(p->right);
            if (p->left != NULL) st.push(p->left);
        }
        return ans;
    }
};
// @lc code=end

