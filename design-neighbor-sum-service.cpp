class NeighborSum {
public:
    vector<vector<int>> mat;
    NeighborSum(vector<vector<int>>& grid) {
        mat = grid;
    }
    
    int adjacentSum(int value) {
        int x, y;
        int n = mat.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == value) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int sum = 0;
        if(x-1 >= 0) sum += mat[x-1][y];
        if(x+1 < n) sum += mat[x+1][y];
        if(y+1 < n) sum += mat[x][y+1];
        if(y-1 >= 0) sum += mat[x][y-1];
        return sum;
    }
    
    int diagonalSum(int value) {
        int x, y;
        int n = mat.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == value) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        int sum = 0;
        int s=x-1, t=y-1;
        while(s >= 0 && t >= 0) {
            sum += mat[s][t];
            break;
        }
        s=x+1, t=y-1;
        while(s < n && t >= 0) {
            sum += mat[s][t];
            break;
        }
        s=x-1, t=y+1;
        while(s >= 0 && t < n) {
            sum += mat[s][t];
            break;
        }
        s=x+1, t=y+1;
        while(s < n && t < n) {
            sum += mat[s][t];
            break;
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */