class Solution {
public:
    int dp[1001][1001];
    int check(string& a, string& b) {
        int i=0, j=0;
        while(i<a.size()&&j<b.size()) {
            if(a[i]==b[j]) i++;
            j++;
        }
        if(i==a.size()) return 1;
        return 0;
    }

    int solve(vector<string>& words, int ind, int prev) {
        int n = words.size();
        if(ind >= n) return 0;
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];

        if(prev==-1) {
            return dp[ind][prev+1] = max(solve(words, ind+1, prev), 1+solve(words, ind+1, ind));
        }
        int len = 0;
        len = solve(words, ind+1, prev);
        if(words[prev].size()==words[ind].size()-1 && check(words[prev],words[ind])) {
            len = max(len, 1+solve(words, ind+1, ind));
        }
        return dp[ind][prev+1] = len;
    }

    static bool cmp(string& a, string& b) {
        return a.size()<b.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        memset(dp,-1,sizeof(dp));
        return solve(words, 0, -1);
    }
};