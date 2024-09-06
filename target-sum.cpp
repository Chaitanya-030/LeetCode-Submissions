class Solution {
public:
    int dp[21][20001];
    int solve(int ind, int target, vector<int>& nums) {
        int n = nums.size();
        if(ind == n && target == 0) return 1;
        if(ind >= n) return 0;
        if(dp[ind][abs(target)] != -1) return dp[ind][abs(target)];

        int plus = nums[ind] + solve(ind+1, target - nums[ind], nums);
        int minus = -nums[ind] + solve(ind+1, target + nums[ind], nums);

        return dp[ind][abs(target)] = minus + plus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(0, target, nums);
    }
};