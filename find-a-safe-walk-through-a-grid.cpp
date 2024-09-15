class Solution {
public:
    int dp[51][51][102];
    int solve(vector<vector<int>>& grid, int i, int j, int n, int m, int k) {
        if(i < 0 || j < 0 || i >= n || j >= m || k < 0 || grid[i][j] == -1) return 0;
        if(i == n-1 && j == m-1) {
            if(grid[i][j] == 1) {
                k--;
                return k>=1;
            }
            if(grid[i][j] == 0) {
                return k>=1;
            }
            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int val = grid[i][j];
        grid[i][j] = -1;
        if(val==1) k--;

        if(solve(grid, i+1, j, n, m, k)) return 1;
        if(solve(grid, i-1, j, n, m, k)) return 1;
        if(solve(grid, i, j+1, n, m, k)) return 1;
        if(solve(grid, i, j-1, n, m, k)) return 1;

        if(val==1) k++;
        grid[i][j] = val;
        return dp[i][j][k] = 0;
    }
    
    bool findSafeWalk(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -1, sizeof(dp));
        
        return solve(grid, 0, 0, n, m, k);
    }
};