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
    ListNode* find(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* low, ListNode* high) {
        if(low == NULL || high == NULL) return high;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;

        while(low && high) {
            if(low->val < high->val) {
                temp->next = low;
                temp = low;
                low = low->next;
            }
            else {
                temp->next = high;
                temp = high;
                high = high->next;
            }
        }

        while(low) {
            temp->next = low;
            temp = low;
            low = low->next;
        }

        while(high) {
            temp->next = high;
            temp = high;
            high = high->next;
        }


        ans = ans->next;
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mid = find(head);
        ListNode* low = head;
        ListNode* high = mid->next;
        mid->next = NULL;

        low = sortList(low);
        high = sortList(high);
        ListNode* ans = merge(low, high);

        return ans;
    }
};