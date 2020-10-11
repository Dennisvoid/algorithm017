/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<Node*> st;
        st.push(root);
        Node* p = NULL;
        while (!st.empty()) {
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            for (int i = p->children.size() - 1; i >= 0; i--) {
                st.push(p->children[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

