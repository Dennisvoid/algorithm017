/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
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
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        stack<Node*> s1; stack<Node*> s2;
        Node* p = NULL;
        s1.push(root);
        while(!s1.empty()) {
            p = s1.top();
            s1.pop();
            s2.push(p);
            for (int i = 0; i < p->children.size(); i++) {
                s1.push(p->children[i]);
            }
        }
        while(!s2.empty()) {
            p = s2.top();
            s2.pop();
            ans.push_back(p->val);
        }
        return ans;
        
    }
};
// @lc code=end

