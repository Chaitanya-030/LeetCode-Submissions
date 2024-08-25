class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> pq;

        for(auto it1 : nums1) {
            for(auto it2 : nums2) {
                int sum = it1+it2;
                if(pq.size() < k) {
                    pq.push({sum, {it1, it2}});
                }
                else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {it1, it2}});
                }
                else {
                    break;
                }
            }
        }

        for(int i=0;i<k;i++) {
            vector<int> temp;
            temp.push_back(pq.top().second.first);
            temp.push_back(pq.top().second.second);
            ans.push_back(temp);
            pq.pop();
        }
        
        return ans;
    }
};