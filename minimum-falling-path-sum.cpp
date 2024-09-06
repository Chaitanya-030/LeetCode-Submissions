class Solution {
public:
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(j>=mat[0].size()) return 1e9;
        if(i==mat.size()-1) return mat[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=f(i+1,j-1,mat,dp);
        int down=f(i+1,j,mat,dp);
        int right=f(i+1,j+1,mat,dp);
        return dp[i][j]=mat[i][j]+min(left,min(down,right));
    }

    int minFallingPathSum(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        int res=INT_MAX;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            int point=f(0,j,mat,dp);
            res=min(res,point);
        }
        return res;
    }
};