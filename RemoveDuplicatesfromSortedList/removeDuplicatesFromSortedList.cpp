/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	for (ListNode *p = head; p && p->next;) {
    		if (p->val == p->next->val) {
    			p->next = p->next->next;
    			continue;
    		}
    		p = p->next;
    	}
        return head;
    }
};

int main() 
{
	ListNode *node0 = new ListNode(1);
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	node0->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	Solution s = Solution();
	ListNode *r = s.deleteDuplicates(node0);
	while(r != NULL) {
		cout << r->val << endl;
		r = r->next;
	}
}