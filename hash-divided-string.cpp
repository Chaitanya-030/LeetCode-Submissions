class Solution {
public:
    string stringHash(string s, int k) {
        string str = "";
        for(int i=0;i<s.size();i+=k) {
            int ans = 0;
            for(int j=i;j<i+k;j++) {
                ans += s[j] - 'a';
            }
            // ans += (s[j] - '0');
            // cout<<ans<<endl;
            str += 'a' + ans%26;
        }
        return str;
    }
};