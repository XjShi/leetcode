/*
 *	Reverse a singly linked list.
 */

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
        ListNode *p = NULL, *h = NULL;
        while(head) {
            p = head;
            head = head->next;
            p->next = h;
            h = p;
        }
        return h;
    }
};