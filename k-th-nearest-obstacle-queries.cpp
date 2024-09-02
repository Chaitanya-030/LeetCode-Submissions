class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        priority_queue<int> pq;
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int dist = abs(x) + abs(y);
            pq.push(dist);
            if(pq.size() < k) ans[i] = -1;
            else {
                if(pq.size() > k) pq.pop();
                ans[i] = pq.top();
            }
        }
        return ans;
    }
};