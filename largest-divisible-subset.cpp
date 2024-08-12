class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int mi = 0;
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), pre(n, -1);
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0 && dp[i] < dp[j]+1) {
                    dp[i]=dp[j]+1;
                    pre[i]=j;
                }
            }
            if(dp[mi] < dp[i]) mi=i;
        }
        vector<int> ans;
        while(mi>=0) {
            ans.push_back(nums[mi]);
            mi=pre[mi];
        }
        return ans;
    }
};