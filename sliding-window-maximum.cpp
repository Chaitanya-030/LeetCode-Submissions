class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        int i = 0, j = 0;
        // while(j < n) {
        //     pq.push({nums[j], j});
        //     if(j - i + 1 == k) {
        //         while(pq.top().second < i) {
        //             pq.pop();
        //         }
        //         if(pq.top().second >= i) {
        //             ans.push_back(pq.top().first);
        //         }
        //         i++;
        //     }
        //     j++;
        // }

        while(j < n) {
            pq.push({nums[j], j});
            if(j - i + 1 == k) {
                while(pq.top().second < i) {
                    pq.pop();
                }
                if(pq.top().second >= i) {
                    ans.push_back(pq.top().first);
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};