class Solution {
public:
    int func(vector<vector<int>>& mat, int n, int m, int col){
        int maxi = -1;
        int ind = -1;
        for(int i=0;i<n;i++) {
            if(mat[i][col] > maxi) {
                maxi = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            int rowind = func(mat, n, m, mid);
            int l, r;
            if(mid-1>=0) l=mat[rowind][mid-1];
            else l=-1;
            if(mid+1<m) r=mat[rowind][mid+1];
            else r=-1;

            if(mat[rowind][mid] > l && mat[rowind][mid] > r) return {rowind, mid};
            else if(mat[rowind][mid] < l) {
                high = mid-1;
            }
            else low=mid+1;
        }
        return {-1,-1};
    }
};