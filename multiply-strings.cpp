class Solution {
public:
    string multiply(string s, string t) {
        if(s == "0" || t == "0") return "0";

        int n = s.size();
        int m = t.size();

        vector<int> v(n+m, 0);
        for(int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                v[i+j+1] += (s[i] - '0') * (t[j] - '0');
                v[i+j] += v[i+j+1]/10;
                v[i+j+1] %= 10;
            }
        }

        int i = 0;
        while (i < v.size() && v[i] == 0) i++;
        string ans = "";
        while (i < v.size()) {
            ans.push_back(v[i] + '0');
            i++;
        }
        
        return ans;
    }
};