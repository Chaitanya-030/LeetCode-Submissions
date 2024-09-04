class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char currDir = 'N';
        int x = 0, y = 0;
        int n = commands.size();
        set<pair<int,int>> st;
        for (auto it:obstacles) {
            st.insert({it[0],it[1]});
        }
        
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (commands[i] == -1) {
                if (currDir == 'N') currDir = 'E';
                else if (currDir == 'E') currDir = 'S';
                else if (currDir == 'S') currDir = 'W';
                else if (currDir == 'W') currDir = 'N';
            } 
            else if (commands[i] == -2) {
                if (currDir == 'N') currDir = 'W';
                else if (currDir == 'W') currDir = 'S';
                else if (currDir == 'S') currDir = 'E';
                else if (currDir == 'E') currDir = 'N';
            } 
            else {
                // bool fl = false;
                for (int j = 0;j<commands[i];j++) {
                    int nx = x, ny = y;
                    if (currDir == 'N') ny = y + 1;
                    else if (currDir == 'E') nx = x + 1;
                    else if (currDir == 'S') ny = y - 1;
                    else if (currDir == 'W') nx = x - 1;
                    if (st.find({nx, ny}) != st.end()) {
                        // fl = true;
                        break;
                    }
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x+y*y);
                }
                // if (fl) continue;
            }
            
        }
        return ans;
    }
};
