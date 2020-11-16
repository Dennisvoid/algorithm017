/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode {
        vector<struct TrieNode*> list;
        string str;
        TrieNode() {
            list = vector<struct TrieNode*> (26, NULL);
        }
        TrieNode(const struct TrieNode& t) {
            for (int i = 0; i < 26; i++) {
                list[i] = t.list[i];
                str = t.str;
            }
        }
    };
    typedef struct TrieNode TrieNode;

    TrieNode root;

    Trie() {
        root = TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* temp = &root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->list[word[i] - 97] == NULL) {
                temp->list[word[i] - 97] = new TrieNode();
            }
            temp = temp->list[word[i] - 97];
            if (i == word.size() - 1) {
                temp->str = word;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* temp = &root;
        for (int i = 0; i < word.size(); i++) {
            if (temp->list[word[i] - 97] == NULL) {
                return false;
            }
            temp = temp->list[word[i] - 97];
        }
        return temp->str == word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* temp = &root;
        for (int i = 0; i < prefix.size(); i++) {
            if (temp->list[prefix[i] - 97] == NULL) {
                return false;
            }
            temp = temp->list[prefix[i] - 97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

