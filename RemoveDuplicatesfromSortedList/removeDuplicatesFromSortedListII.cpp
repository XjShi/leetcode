/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
	/*
	 *	思路：两个指针，一个指针先走n步，然后两个指针一起走，先走的指针到链表尾的时候，后走的指针走了(length-n)步。
	 */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        head = &dummy;
        
        ListNode *p1 = head, *p2 = head;
        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }
        while(p1->next) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return head->next;
    }
};