class Solution {
public:
    bool isPalindrome(string s) {
        // transform(s.begin(), s.end(), s.begin(), ::tolower); 
        // cout<<s<<endl;

        int n = s.size();
        int i = 0, j = n-1;
        while(i <= j) {
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }
            if(tolower(s[i]) != tolower(s[j])) return 0;
            else {
                i++;
                j--;
            }
        }
        return 1;
    }
};