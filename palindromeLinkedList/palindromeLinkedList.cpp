/**
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
	//把链表的后半段反转，然后比较前半段和后半段
    bool isPalindrome(ListNode* head) {
    	ListNode *fast = head, *slow = head;
    	while (fast && fast->next) {
    		fast = fast->next->next;
    		slow = slow->next;
    	}
    	if (fast) {
    		//链表中有奇数个元素
    		slow->next = reverse(slow->next);
    		slow = slow->next;
    	} else {
    		slow = reverse(slow);
    	}

    	while(slow) {
    		if (slow->val != head->val)
    			return false;
    		slow = slow->next;
    		head = head->next;
    	}
    	return true;
    }

    ListNode *reverse(ListNode *head) {
    	ListNode *p = NULL, *h = NULL;
    	while (head) {
    		p = head;
    		head = head->next;
    		p->next = h;
    		h = p;
    	}
    	return h;
    }
};