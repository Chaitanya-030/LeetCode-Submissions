class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            int val = mp[s[i]];
            int f = 0;
            for(int j=i+1;j<n;j++) {
                if(mp[s[j]] > val) {
                    ans -= val;
                    f = 1;
                    break;
                }
            }
            if(f == 0) ans += val;
        }
        return ans;
    }
};