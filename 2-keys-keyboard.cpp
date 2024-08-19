class Solution {
public:
    int solve(int n, int curr, int lastCopy, vector<vector<int>>& dp) {
        if(curr == n) return 0;

        if(curr > n || lastCopy > n) return 1e9;

        if(dp[curr][lastCopy] != -1) return dp[curr][lastCopy];

        int copy = 2 + solve(n, curr + curr, lastCopy, dp);
        int paste = 1 + solve(n, curr + lastCopy, lastCopy, dp);

        return dp[curr][lastCopy] = min(copy, paste);
    }

    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        if(n == 1) return 0;
        return 1 + solve(n, 1, 1, dp);
    }
};