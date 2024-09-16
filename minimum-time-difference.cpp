class Solution {
public:
    int solve(string& s1, string& s2) {
        int h1 = stoi(s1.substr(0,2));
        int h2 = stoi(s2.substr(0,2));
        int m1 = stoi(s1.substr(3));
        int m2 = stoi(s2.substr(3));

        int t1 = h1*60 + m1;
        int t2 = h2*60 + m2;
        int diff = abs(t1-t2);
        diff = min(diff, 1440-diff);

        return diff;
    }

    int findMinDifference(vector<string>& tp) {
        sort(tp.begin(), tp.end());
        int n = tp.size();

        int ans = INT_MAX;
        for(int i=1;i<n;i++) {
            ans = min(ans, solve(tp[i-1], tp[i]));
        }
        ans = min(ans, solve(tp[0], tp[n-1]));
        return ans;
    }
};