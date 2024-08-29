class Solution {
public:
    void dfs(int n, int ind, vector<int>& vis, vector<vector<int>>& stones) {
        vis[ind] = 1;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                if(stones[ind][0] == stones[i][0]) dfs(n, i, vis, stones);
                if(stones[ind][1] == stones[i][1]) dfs(n, i, vis, stones);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int cnt = 0;
        vector<int> vis(n, 0);
        for(int i=0;i<n;i++) {
            if(!vis[i]) {
                dfs(n, i, vis, stones);
                cnt++;
            }
        }
        return n-cnt;
    }
};