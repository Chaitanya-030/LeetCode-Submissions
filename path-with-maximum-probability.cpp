class Solution {
public:
    double f_ans = 0;
    double mini = 1e-5;
    void dfs(int node, int dst, vector<pair<int, double>> adj[], vector<int>& vis, int n, double ans) {
        if(ans <= mini) return;

        if(node == dst) {
            f_ans = max(f_ans, ans);
            return;
        }

        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it.first] && ans*it.second >= f_ans) {
                dfs(it.first, dst, adj, vis, n, ans*it.second);
            }
        }
        vis[node] = 0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& success, int start, int end) {
        vector<pair<int, double>> adj[n];
        int i = 0;
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], success[i]});
            adj[it[1]].push_back({it[0], success[i]});
            i++;
        }

        vector<int> vis(n, 0);
        dfs(start, end, adj, vis, n, 1);
        return f_ans;
    }
};