class Solution {
public:
    int f(int ind, vector<int>& dp, int n){
        if(ind == n) return 1;
        // if(ind > n) return 0;
         
        if(dp[ind] != -1) return dp[ind];
        int one = 0;
        if(ind+1<=n) one = f(ind+1, dp, n);
        int two = 0;
        if(ind+2<=n) two = f(ind+2, dp, n);;

        return dp[ind] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        int ans = f(0, dp, n);
        return ans;
    }
};