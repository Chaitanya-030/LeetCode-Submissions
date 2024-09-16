class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> v(26,0);
        v['a'-'a'] = 1;
        v['e'-'a'] = 2;
        v['i'-'a'] = 4;
        v['o'-'a'] = 8;
        v['u'-'a'] = 16;

        int x = 0;
        int ans = 0;
        map<int, int> mp;
        mp[0] = -1;
        for(int i=0;i<n;i++) {
            char ch = s[i];
            x ^= v[ch-'a'];
            if(mp.find(x) == mp.end()) mp[x] = i;
            ans = max(ans, i-mp[x]);
        }
        return ans;
    }
};