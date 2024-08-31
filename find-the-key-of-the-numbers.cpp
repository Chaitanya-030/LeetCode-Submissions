class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        string s = "";
        while(num1 && num2 && num3) {
            int d1 = num1%10;
            int d2 = num2%10;
            int d3 = num3%10;
            s += to_string(min({d1, d2, d3}));
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        while(s.size() < 4) {
            s += '0';
        }
        reverse(s.begin(), s.end());
        return stoi(s);;
    }
};