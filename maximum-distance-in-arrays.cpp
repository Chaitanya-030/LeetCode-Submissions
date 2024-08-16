class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<pair<int, int>> v;
        int cnt = 0;
        for(auto it : arrays) {
            cnt++;
            int n = it.size();
            v.push_back({it[0], cnt});
            v.push_back({it[n-1], cnt});
        }
        sort(v.begin(), v.end());
        
        int val1 = v[0].first;
        int cnt1 = v[0].second;
        int val2 = v[v.size()-1].first;
        int cnt2 = v[v.size()-1].second;

        int ans = INT_MIN;

        for(auto it : v) {
            if(it.second!=cnt2) {
                ans = val2-it.first;
                break;
            }
        }

        for(int i=v.size()-1;i>=0;i--) {
            if(v[i].second!=cnt1) {
                ans = max(ans, v[i].first-val1);
            }
        }

        return ans;
    }
};