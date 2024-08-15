class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int cnt = 0;
        int f = 0;
        for(int i=n-1;i>=0;i--) {
            if(s[i] == ' ' && f == 1) break;
            if(s[i] == ' ' && f == 0) continue;
            f = 1;
            cnt++;
        }
        return cnt;
    }
};