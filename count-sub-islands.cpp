class Solution {
public:
    int f = 0;
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int n, int m) {
        if(grid1[i][j] != grid2[i][j]) {
            f = 0;
        }

        grid2[i][j] = 0;
        grid1[i][j] = 0;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && grid2[ni][nj] == 1) {
                dfs(ni, nj, grid1, grid2, n, m);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0;
        int n = grid1.size();
        int m = grid1[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid2[i][j] == 1) {
                    f = 1;
                    dfs(i, j, grid1, grid2, n, m);
                    if(f) cnt++;
                }
            }
        }
        return cnt;
    }
};