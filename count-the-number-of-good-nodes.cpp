class Solution {
public:
    int ans;
    int dfs(int node, vector<int> adj[], int par, int& ans) {
        int sz = -1, flag = 1, temp = 0;
        for(auto it : adj[node]) {
            if(it != par) {
                int cst = dfs(it, adj, node, ans);
                temp += cst;
                if(sz == -1) sz = cst;
                else if(sz != cst) flag = 0;
            }
        }
        ans += flag;
        return 1 + temp;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj[n+1];
        ans = 0;
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0, adj, -1, ans);
        return ans;
    }
};