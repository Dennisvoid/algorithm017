#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() {
        val = INT_MIN;
        left = NULL;
        right = NULL;
    }
    TreeNode(const TreeNode& node) {
        val = node.val;
        left = node.left;
        right = node.right;
    }
};

typedef struct BiSearchTree BiSearchTree;
struct BiSearchTree {
    TreeNode root;
    BiSearchTree() {
        root = new TreeNode();
    }
    BiSearchTree(const BiSearchTree& BST) {
        TreeNode* p = root;
        TreeNode* q = NULL;
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push(pair(root, BST.root));
        while (!st.empty()) {
            p = st.top().first;
            q = st.top().second;
            st.pop();
            p->val = q->val;
            if (q->right != NULL) {
                p->right = new TreeNode();
                st.push(pair(p->right, q->right));
            }
            if (q->left != NULL) {
                p->left = new TreeNode();
                st.push(pair(p->left, q->left));
            }
        }
    }

    bool insert_node(int value, TreeNode* TreeRoot = root) {
        if (TreeRoot->val == INT_MIN && TreeRoot->left == NULL && TreeRoot->right == NULL) {
            TreeRoot->val = value;
            return true;
        }
        if (value == TreeRoot->val) return false;
        else if (value < TreeRoot->val) {
            if (TreeRoot->left == NULL) {
                TreeRoot->left = new TreeNode(value);
                return true;
            }
            return insert_node(value, TreeNode->left);
        }
        else {
            if (TreeRoot->right == NULL) {
                TreeRoot->right = new TreeNode(value);
                return true;
            }
            return insert_node(value, TreeNode->right);
        }
    }

    TreeNode* delete_node(int value, TreeNode* TreeRoot = root) {
        if (TreeRoot == NULL) return NULL;
        if (TreeRoot->val == value) {
            if (TreeRoot->left == NULL && TreeRoot->right == NULL) {
                free(TreeRoot);
                return NULL;
            }
            else if (TreeRoot->left != NULL && TreeRoot->right == NULL) {
                TreeNode* temp = TreeRoot->left;
                free(TreeRoot);
                return temp;
            }
            else if (TreeRoot->left == NULL && TreeRoot->right != NULL) {
                TreeNode* temp = TreeRoot->right;
                free(TreeRoot);
                return temp;
            }
            else {
                TreeNode* temp = TreeRoot->left;
                TreeNode* prev = TreeRoot;
                while(temp->right != NULL) {
                    prev = temp;
                    temp = temp->right;
                }
                if (temp->left != NULL) {
                    prev->right = temp->left;
                }
                TreeRoot->val = temp->val;
                free(temp);
                return TreeRoot;
            }
        }
        else if (value < TreeRoot->val) {
            TreeRoot->left = delete_node(value, TreeRoot->left);
            return TreeRoot;
        }
        else {
            TreeRoot->right = delete_node(value, TreeRoot->right);
            return TreeRoot;
        }
    }

    TreeNode* search_node(int value, TreeNode* TreeRoot = root) {
        if (TreeRoot == NULL) return NULL;
        if (TreeRoot->val == value) return TreeRoot;
        else if (value < TreeRoot->val) {
            return search_node(value, TreeRoot->left);
        }
        else {
            return search_node(value, TreeRoot->right);
        }
    }

    int getMin() {
        TreeNode* p = root;
        if (p == NULL) return INT_MIN;
        while (p->left != NULL) {
            p = p->left;
        }
        return p->val;
    }

    int getMax() {
        TreeNode* p = root;
        if (p == NULL) return INT_MIN;
        while (p->right != NULL) {
            p = p->right;
        }
        return p->val;
    }
};