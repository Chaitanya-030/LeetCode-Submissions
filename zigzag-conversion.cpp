class Solution {
public:
    string convert(string s, int r) {
        int n = s.size();
        vector<string> ans(r);
        int f = 0;
        int ind = 0;
        for(int i=0;i<n;i++) {
            if(ind >= r) ind=r-1;
            if(ind < 0) ind=0;
            if(ind == 0) {
                f = 0;
            }
            else if(ind == r-1) {
                f = 1; 
            }
            ans[ind].push_back(s[i]);
            if(f) ind--;
            else ind++;
        }

        string f_ans = "";
        for(auto it : ans) {
            for(auto x : it) f_ans += x;
            // cout<<endl;
        }
        return f_ans;
    }
};