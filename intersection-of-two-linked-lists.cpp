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
        int n = 0, m = 0;
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != NULL) {
            a = a->next;
            n++;
        }
        while(b != NULL) {
            b = b->next;
            m++;
        }

        int x= abs(n-m);
        if(n > m) {
            while(x--) {
                headA = headA->next;
            }
        }
        else {
            while(x--) {
                headB = headB->next;
            }
        }

        while(headA && headB) {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};