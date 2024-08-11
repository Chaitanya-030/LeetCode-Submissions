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
    ListNode* temp;
    int solve(ListNode* head) {
        if(head == NULL) return 1;

        int x = solve(head->next) && (temp->val == head->val);
        temp = temp->next;
        return x;
    }

    bool isPalindrome(ListNode* head) {
        temp = head;
        return solve(head);
    }
};