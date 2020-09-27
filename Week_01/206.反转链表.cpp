/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* p = head; 
        ListNode* prev = NULL;
        while (p != NULL) {
            ListNode* temp = p;
            p = p->next;
            temp->next = prev;
            prev = temp;
        }
        return prev;
    }
};
// @lc code=end

