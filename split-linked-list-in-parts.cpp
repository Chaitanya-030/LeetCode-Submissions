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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz = 0;
        ListNode* curr = head;
        while(curr) {
            sz++;
            curr = curr->next;
        }

        int cnt = sz/k;
        int x = sz%k;

        vector<ListNode*> ans;
        curr = head;

        for(int i=0;i<k;i++) {
            ListNode* temp = curr;
            int tsz = cnt + (x>0);
            x--;

            for(int j=0;j<tsz-1&&curr;j++) {
                curr = curr->next;
            }

            if(curr) {
                ListNode* nxt = curr->next; 
                curr->next = NULL;  
                curr = nxt;
            }

            ans.push_back(temp);
        }
        return ans;
    }
};