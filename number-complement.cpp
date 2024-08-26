class Solution {
public:
    int findComplement(int num) {
        int ans = 0, i = 0;
        while(num) {
            int sb = num&1;
            if(!sb) {
                ans += pow(2,i);
            }
            num >>= 1;
            i++;
        }
        return ans;
    }
};