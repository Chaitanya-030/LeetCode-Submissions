class Solution {
public:
    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& vis) {
        int n = mat.size();
        vis[i][j] = 1;

        for(int k=0;k<4;k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if(ni >= 0 && nj >= 0 && ni < n && nj < n && mat[ni][nj] == 0 && !vis[ni][nj]) {
                dfs(ni, nj, mat, vis);
            }
        }
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> mat(3*n, vector<int>(3*n, 0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '/') {
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\') {
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }

        int cnt = 0;
        vector<vector<int>> vis(3*n, vector<int>(3*n, 0));
        for(int i=0;i<3*n;i++) {
            for(int j=0;j<3*n;j++) {
                if(mat[i][j] == 0 && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, mat, vis);
                }
            }
        }
        return cnt;
    }
};