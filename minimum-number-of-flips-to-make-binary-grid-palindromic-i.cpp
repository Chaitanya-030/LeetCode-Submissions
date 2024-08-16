class Solution {
public:
    int check(string& s) {
        int i = 0, j = s.size()-1;
        int cnt = 0;
        while(i < j) {
            if(s[i] != s[j]) cnt++;
            i++;
            j--;
        }
        return cnt;
    }

    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0, ans = 0;
        for(int i=0;i<n;i++) {
            string s = "";
            for(int j=0;j<m;j++) {
                s += to_string(grid[i][j]);
            }
            cnt += check(s);
        }

        ans = cnt;
        cnt = 0;

        for(int i=0;i<m;i++) {
            string s = "";
            for(int j=0;j<n;j++) {
                s += to_string(grid[j][i]);
            }
            cnt += check(s);
        }

        return min(ans,cnt);
    }
};