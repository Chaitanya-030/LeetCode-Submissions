class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        vector<vector<int>> ans;
        int k = o.size();
        vector<int> temp;
        int cnt = 0;
        for(int i=0;i<k;i++) {
            temp.push_back(o[i]);
            if((i+1)%n == 0) {
                cnt += temp.size();
                ans.push_back(temp);
                temp.clear();
            }
        }
        cnt += temp.size();
        if(cnt != m*n) return {};
        return ans;
    }
};