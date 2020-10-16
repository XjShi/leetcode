/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *pa = l1, *pb = l2;
        ListNode *result, *pc;
        result = pc = ListNode(0);
        while(pa && pb) {
        	if (pa->val < pb->val) {
        		pc->next = pa;
        		pc = pa;
        		pa = pa->next;
        	} else {
        		pc->next = pb;
        		pc = pb;
        		pb = pb->next;
        	}
        }
        pc->next = pa ? pa : pb;
        return result->next;
    }
};