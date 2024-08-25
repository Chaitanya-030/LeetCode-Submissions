#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        ll ans = 0;
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;

        for(int i=0;i<c;i++) {
            pq1.push(costs[i]);
            if(i < n-c) {
                pq2.push(costs[n-i-1]);
            }
        }

        int i = c-1;
        int j = n-c;
        while(k--) {
            if(pq1.empty() || (pq2.size() && pq2.top() < pq1.top())) {
                ans += pq2.top();
                pq2.pop();
                j--;
                if(j > i) pq2.push(costs[j]);
            }
            else {
                ans += pq1.top();
                pq1.pop();
                i++;
                if(i < j) pq1.push(costs[i]);
            }
        }
        return ans;
    }
};