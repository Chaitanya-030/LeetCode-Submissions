class Solution {
public:
    bool solve(string s, string p, int i, int j, vector<vector<int>>& dp) {
        int n = s.size();
        int m = p.size();
        if(j >= m && i >= n) return true;
        if(j >= m) return false;

        if(i >= n) {
            while(j < m) {
                if(p[j] != '*') return false;
                j++;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s, p, i+1, j+1, dp);
        }

        if(p[j] == '*') {
            return dp[i][j] = solve(s, p, i, j+1, dp) || solve(s, p, i+1, j, dp);
        }
        return false;;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s, p, 0, 0, dp);
    }
};