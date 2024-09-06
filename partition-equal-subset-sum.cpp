class Solution {
public:
    int dp[201][20001];
    bool solve(int ind, vector<int>& nums, int req, int n) {
        if(req == 0) return 1;
        if(ind >= n) return 0;
        if(dp[ind][req] != -1) return dp[ind][req];

        bool take = 0;
        if(nums[ind]<=req) take = solve(ind+1, nums, req-nums[ind], n);
        bool nottake = solve(ind+1, nums, req, n);

        return dp[ind][req] = take || nottake;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums) sum += it;

        if(sum%2 == 1) return false;
        memset(dp, -1, sizeof(dp));
        // vector<vector<int>> dp(n + 1, vector<int>(sum/2 + 1, -1));
        return solve(0, nums, sum/2, n);
    }
};