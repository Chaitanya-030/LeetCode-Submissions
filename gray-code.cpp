class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int m = (1<<n);
        for(int i=0;i<m;i++) {
            ans.push_back(i^(i/2));
        }
        return ans;
    }
};