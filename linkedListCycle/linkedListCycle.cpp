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
	检测环
	*/
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast) {
            if (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            }
            else {
                return false;
            }
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }

    /**
    判断是否有环，如果有环，返回环的起始结点；如果没有环，返回null。
    **/
    ListNode *detectCycle(ListNode *head) {
    	ListNode *slow = head, *fast = head;
    	bool flag = false;
    	while (fast) {
    		if (fast->next && fast->next->next) {
    			fast = fast->next->next;
    			slow = slow->next;
    		}
    		else {
    			return NULL;
    		}
    		if (fast == slow) {
    			flag = true;
    			break;
    		}
    	}    
    	if (flag) {
    		slow = head;
    	}
    	while(fast != slow) {
    		fast = fast->next;
    		slow = slow->next;
    	}
    	return slow;
    }
};