class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for(auto it : rolls) sum += it;
        int totsum = mean*(n+m);
        int rem = totsum - sum;

        if(rem < n) return {};

        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = rem/n;
        }
        int rem2 = rem%n;
        int i = 0;
        while(rem2--) {
            ans[i]++;
            i++;
        }

        for(int i=0;i<n;i++) {
            if(ans[i] > 6) return {};
        }
        return ans;
    }
};