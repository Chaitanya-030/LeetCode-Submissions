#define mod 1000000007

class Solution {
public:
    long long power(long long x, long long n){
        if(n == 0) return 1;
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n%2==1){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long cnto = n/2;
        long long cnte = n/2+n%2;
        return (power(5, cnte)*(power(4,cnto))%mod);
    }
};