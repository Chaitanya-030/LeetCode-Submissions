class Solution {
public:
    // long long dp[100001][2];
    long long solve(vector<int>& a, vector<int>& b, int ch, int cd, vector<vector<long long>>& dp) {
        int n = a.size();
        if(ch >= n) return 0;

        if(dp[ch][cd] != -1) return dp[ch][cd];

        long long x;
        if(cd == 0) x = a[ch];
        else x = b[ch];

        long long take = x + solve(a, b, ch+1, cd, dp);
        long long nottake = x + solve(a, b, ch+2, !cd, dp);

        return dp[ch][cd] = max(take, nottake);
    }

    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        long long ans1 = solve(a, b, 0, 0, dp);
        long long ans2 = solve(a, b, 0, 1, dp);
        return max(ans1, ans2);
    }
};