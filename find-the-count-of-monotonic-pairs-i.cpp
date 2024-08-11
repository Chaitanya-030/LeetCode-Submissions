class Solution {
public:
    int dp[2001][52][52];
    int mod = 1e9 + 7;
    int solve(int ind, vector<int>& nums, int prev1, int prev2) {
        int n = nums.size();
        if(ind == n) return 1;
        if(dp[ind][prev1][prev2] != -1) return dp[ind][prev1][prev2];

        int cnt = 0;
        for(int k=prev1;k<=nums[ind];k++) {
            int x1 = k;
            int x2 = nums[ind] - k;
            if(x2 <= prev2) {
                cnt = (cnt + solve(ind+1, nums, x1, x2))%mod;
            }
        }
        return dp[ind][prev1][prev2] = cnt;
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        int cnt = solve(0, nums, 0, 50);
        return cnt;
    }
};