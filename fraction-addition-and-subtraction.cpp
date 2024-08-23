class Solution {
public:
    string fractionAddition(string s) {
        int num = 0, den = 1;
        int i=0;
        int n = s.size();

        while(i<n) {
            int r=1;
            if(s[i] == '+' || s[i] == '-') {
                if(s[i] == '-') r=-1;
                i++;
            }

            int y=0;
            while(i<n && isdigit(s[i])) {
                y=y*10+(s[i]-'0');
                i++;
            }

            y*=r;
            i++;

            int e=0;
            while(i<n && isdigit(s[i])) {
                e=e*10+(s[i]-'0');
                i++;
            }
            
            num=num*e+den*y;
            den*=e;

            int gc = gcd(abs(num), den);
            num/=gc;
            den/=gc;
        }
        return to_string(num)+'/'+to_string(den);
    }
};