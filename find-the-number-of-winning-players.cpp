class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        vector<vector<int>> mat(n, vector<int>(11, 0));
        for(auto it : pick) {
            int player = it[0];
            int ball = it[1];
            mat[player][ball]++;
        }

        vector<int> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<11;j++) {
                if(mat[i][j] > i) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans.size();
    }
};