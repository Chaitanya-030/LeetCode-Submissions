class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=31;i>=0;i--) {
            int sum = 0;
            for(auto it : nums) {
                if(it & (1<<i)) sum++;
            }

            sum = sum%3;
            if(sum) ans = ans | 1<<i;
        }
        return ans;
    }
};