/**
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
**/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode result(0);
        result.next = head;
        ListNode *p = &result;

        while (p->next) {
        	if (p->next->val == val) {
        		p->next = p->next->next;
        	} else {
        		p = p->next;
        	}
        }
        return result.next;
    }
};