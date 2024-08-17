class Solution {
public:
    long long solve(int i, vector<vector<int>>& mat, int n, int m, int prev, vector<vector<long long>>& dp) {
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        long long sum = 0;
        for(int j=0;j<m;j++) {
            if(prev == -1) {
                sum = max(sum, mat[i][j] + solve(i+1, mat, n, m, j, dp));
            }
            else {
                sum = max(sum, mat[i][j] - abs(j-prev) + solve(i+1, mat, n, m, j, dp));
            }
        }
        return dp[i][prev+1] = sum;
    }

    long long maxPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m, -1));
        for(int i=0;i<m;i++) {
            dp[0][i] = mat[0][i];
        }

        for(int i=1;i<n;i++) {
            vector<long long int> leftMax(m);
            vector<long long int> rightMax(m);

            long long int maxi = 0;
            for(int j=0;j<m;j++) {
                maxi=max(maxi-1,dp[i-1][j]);
                leftMax[j] = maxi;
            }
            
            maxi = 0;
            for(int j=m-1;j>=0;j--) {
                 maxi=max(maxi-1,dp[i-1][j]);
                 rightMax[j] = maxi;
            }
  
            for(int j=0;j<m;j++) {
                dp[i][j]=max(leftMax[j],rightMax[j])+mat[i][j];  
            }
        }

        long long int ans = 0;
        for(int i=0;i<m;i++) {
            ans=max(dp[n-1][i],ans);
        }
        return ans;
    }
};