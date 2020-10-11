/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    typedef enum{L, R} Tag;
    struct Node{
        TreeNode* pt;
        Tag tag;
        Node(){
            pt = NULL;
            tag = L;
        }
        Node(TreeNode* p, Tag t = L) {
            pt = p;
            tag = t;
        }
        Node(const Node& node) {
            pt = node.pt;
            tag = node.tag;
        }
    };
    typedef struct Node Node;
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<Node> st;
        TreeNode* p = root;
        do {
            while(p != NULL) {
                Node temp(p);
                st.push(temp);
                p = p->left;
            }
            int if_continue = 1;
            while (if_continue == 1 && !st.empty()) {
                Node temp(st.top());
                st.pop();
                p = temp.pt;
                switch(temp.tag) {
                    case L : {
                        temp.tag = R;
                        st.push(temp);
                        p = p->right;
                        if_continue = 0;
                        break;
                    }
                    case R : {
                        ans.push_back(p->val);
                        break;
                    }
                }
            }
        }while(!st.empty());
        return ans;
    }
};
// @lc code=end

