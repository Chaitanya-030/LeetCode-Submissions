class Solution {
public:
    int dp[101][101];
    int solve(string& s, string& t, string& w, int i, int j) {
        if(i+j == w.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(i < s.size() && s[i]==w[i+j]) {
            ans |= solve(s,t,w,i+1,j);
        }
        if(j < t.size() && t[j]==w[i+j]) {
            ans |= solve(s,t,w,i,j+1);
        }
        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int p = s3.size();
        memset(dp, -1, sizeof(dp));
        if(n+m!=p) return 0;
        return solve(s1,s2,s3,0,0);
    }
};