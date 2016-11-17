/**
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if (!headA || !headB)
    		return NULL;

  		ListNode *pA = headA, *pB = headB;
  		int countA = 1, countB = 1;
  		while(pA->next || pB->next) {
  			if (pA->next) {
  				countA++;
  				pA = pA->next;
  			}
  			if (pB->next) {
  				countB++;
  				pB = pB->next;
  			}
  		}      

  		pA = headA;
  		pB = headB;
  		int sub = 0;
  		if (countA > countB) {
  			sub = countA - countB;
  			for (int i=0; i<sub; i++) {
  				pA = pA->next;
  			}
  		} else {
  			sub = countB - countA;
  			for (int i=0; i<sub; i++) {
  				pB = pB->next;
  			}
  		}
  		while (pA && pB) {
  			if (pA == pB)
  				return pA;
  			else {
  				pA = pA->next;
  				pB = pB->next;
  			}
  		}
  		return NULL;
    }
};