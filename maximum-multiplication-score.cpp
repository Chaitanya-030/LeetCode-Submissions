class Solution {
public:
    long long dp[100001][5];
    long long solve(vector<int>& a, vector<int>& b, int ind, int k) {
        if(k == 0) return 0;
        if(ind >= b.size()) return -1e9;
        if(dp[ind][k] != -1) return dp[ind][k];

        long long take = (long long)b[ind]*(long long)a[4-k] + solve(a,b,ind+1,k-1);
        long long nottake = solve(a,b,ind+1,k);

        return dp[ind][k] = max(take, nottake);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        memset(dp, -1, sizeof(dp));
        return solve(a, b, 0, 4);
    }
};