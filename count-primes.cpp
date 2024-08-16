class Solution {
public:
    int N = 5e6+1;
    vector<int> solve(int n) {
        vector<int> sieve(n+1, 1);
        sieve[0] = 0;
        if(n >= 1) sieve[1] = 0;
        for(int i=2;i<=n;i++) {
            if(sieve[i]) {
                for(int j=2*i;j<=n;j+=i) {
                    sieve[j] = 0;
                }
            }
        }
        return sieve;
    }

    int countPrimes(int n) {
        vector<int> s = solve(n);
        int cnt = 0;
        for(int i=2;i<n;i++) {
            if(s[i]) cnt++;
        }
        return cnt;
    }
};