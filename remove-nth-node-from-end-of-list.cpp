/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<k;i++) {
            fast = fast->next;
        }

        while(fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = head;
        if(temp == slow) return head->next;
        while(temp->next && temp->next != slow) {
            temp = temp->next;
        }
        
        temp->next = slow->next;
        
        return head;
    }
};