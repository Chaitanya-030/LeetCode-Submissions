class Solution {
public:
    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] == 1) {
                dfs(ni, nj, grid);
            }
        }
    }

    int connected(vector<vector<int>> grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && ans == 0) {
                    ans = 1;
                    dfs(i, j, grid);
                }
                else if(grid[i][j] == 1) {
                    return 0;
                }
            }
        }
        return ans;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(!connected(grid)) return 0;

        // check by flipping all 1's to 0's
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if(!connected(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};