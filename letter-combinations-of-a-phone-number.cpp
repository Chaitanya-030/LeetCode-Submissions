class Solution {
public:
    string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(string& d, vector<string>& ans, string& temp, int ind, int n) {
        if(ind >= n) {
            ans.push_back(temp);
            return;
        }

        int dig = d[ind] - '0';
        string v = mp[dig];
        for(auto it : v) {
            temp.push_back(it);
            solve(d, ans, temp, ind+1, n);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp = "";
        int n = digits.size();
        if(n == 0) return {};
        solve(digits, ans, temp, 0, n);
        return ans;
    }
};