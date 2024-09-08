class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        int ind = 0, prev = nums[0];
        long long ans = 0;

        for(int i=1;i<nums.size();i++) {
            if(nums[i]>prev) {
                long long temp = i-ind;
                ans += temp*nums[ind];
                prev=nums[i];
                ind=i;
            }
        }
        long long temp = n-1-ind;
        ans += temp*nums[ind];
        return ans;
    }
};