class Solution {
public:
    int dp[2501][2501];
    int f(vector<int>& nums, int ind, int prev){
        if(ind >= nums.size()) return 0;

        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int len = 0;
        len = f(nums, ind+1, prev);
        if(prev == -1 || nums[ind] > nums[prev]){
            len = max(len, 1 + f(nums, ind+1, ind));
        }

        return dp[ind][prev+1] = len;
    }


    // TC : O(n*n)
    int solve(vector<int>& nums, int ind, int prev) {
        if(ind >= nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int len = 0;
        len = solve(nums, ind+1, prev);
        if(prev == -1 || nums[prev] < nums[ind]) {
            len = max(len, 1 + solve(nums, ind+1, ind));
        }
        return dp[ind][prev+1] = len;
    }

    int solve2(vector<int>& nums, int ind, int prev) {
        if(ind >= nums.size()) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        int len = solve2(nums, ind+1, prev);
        if(prev == -1 || nums[prev] < nums[ind]) {
            len = max(len, 1 + solve2(nums, ind+1, ind));
        }

        return dp[ind][prev+1] = len;
    }

    // TC : O(n*log(n))
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // memset(dp, -1, sizeof(dp));
        // return solve2(nums, 0, -1);

        vector<int> ans;
        ans.push_back(nums[0]);

        // for(int i=1;i<n;i++) {
        //     if(nums[i] > ans.back()) ans.push_back(nums[i]);
        //     else {
        //         // remember the example : 1 3 4 5 8 --> insert(2) -->lower bound(2) 
        //         int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
        //         ans[ind] = nums[i];
        //     }
        // }

        // return ans.size();

        for(int i=1;i<n;i++) {
            if(ans.back() < nums[i]) {
                ans.push_back(nums[i]);
            }
            else {
                int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
};