class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end(), greater<>());

        int i = 0, j = 0;
        while(j < n) {
            sum += v[j].second;
            pq.push(v[j].second);

            if(j-i+1<k) j++;
            else {
                ans = max(ans, sum*v[j].first);
                sum -= pq.top();
                pq.pop();
                i++;
                j++;
            }
        }
        return ans;
    }
};