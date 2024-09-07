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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int, int> mp;
        for(auto it : nums) mp[it]++;

        ListNode* curr = head;
        while(curr != NULL) {
            if(mp.count(curr->val) == 0) {
                break;
            }
            curr = curr->next;
        }

        ListNode* prev = curr;
        ListNode* temp = curr;
        if(curr == NULL) return temp;
        curr = curr->next;
        while(curr != NULL) {
            if(mp.count(curr->val) == 0) {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = curr;

        return temp;
    }
};