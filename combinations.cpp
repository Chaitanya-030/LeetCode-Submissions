class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& temp, vector<int>& v, int ind, int k) {
        if(ind >= v.size()) {
            if(k == 0) {
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(v[ind]);
        solve(ans, temp, v, ind+1, k-1);
        temp.pop_back();
        solve(ans, temp, v, ind+1, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, v, 0, k);
        return ans;
    }
};