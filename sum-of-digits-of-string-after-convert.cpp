class Solution {
public:

    int getLucky(string s, int k) {
        string str;
        for(int i=0;i<s.size();i++) {
            int val = s[i] - 'a' + 1;
            str += to_string(val);
        }
        // if(k == 1) return sum;
        // cout<<sum<<endl;
        int f_sum = 0;
        // k--;
        while(k--) {
            int sum = 0;
            for(int i=0;i<str.size();i++) {
                int val = str[i] - '0';
                sum += val;
            }
            str = to_string(sum);
        }
        return stoi(str);
    }
};