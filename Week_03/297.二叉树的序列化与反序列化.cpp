/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> q;
        TreeNode* p = NULL;
        q.push(root);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            if (p == NULL) {
                ans.append("null,");
            }
            else {
                ans.append(to_string(p->val));
                ans.append(1,',');
            }
            if (p != NULL) {
                q.push(p->left);
                q.push(p->right);
            }
        }
        int i;
        for(i = ans.size() - 1; i >= 0; i--) {
            if (ans[i] != ',' && ans[i] != 'n' && ans[i] != 'u' && ans[i] != 'l') {
                break;
            }
        }
        ans.erase(i + 1, ans.size() - 1 - i);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        int i = 0; int j = i;
        for(; i < data.size() && data[i] != ','; i++);
        TreeNode* root = new TreeNode(stoi(data.substr(j,i - j)));
        TreeNode* p = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            p = q.front();
            q.pop();
            i++; j = i;
            for(; i < data.size() && data[i] != ','; i++);
            if (i <= data.size()) {
                if (data[j] != 'n') {
                    p->left = new TreeNode(stoi(data.substr(j,i - j)));
                    q.push(p->left);
                }
            }
            i++; j = i;
            for(; i < data.size() && data[i] != ','; i++);
            if (i <= data.size()) {
                if (data[j] != 'n') {
                    p->right = new TreeNode(stoi(data.substr(j,i - j)));
                    q.push(p->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

