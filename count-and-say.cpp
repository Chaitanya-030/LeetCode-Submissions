class Solution {
public:
    string solve(string s, int n) {
        n -= 2;
        while(n--) {
            int cnt = 1;
            string temp = "";
            int f = 0;
            char a;
            for(int i=0;i<s.size()-1;i++) {
                a = s[i];
                if(s[i] == s[i+1]) {
                    cnt++;
                    f = 1;
                }
                else {
                    temp += to_string(cnt);
                    temp += s[i];
                    cnt = 1;
                    f = 0;
                }
            }
            // if(f == 1) {
            temp += to_string(cnt);
            temp += s[s.size()-1];
            // }
            cout<<temp<<endl;
            s = temp;
            if(n == 0) return temp;
        }
        return s;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";

        string s = "11";
        return solve(s, n);
    }
};