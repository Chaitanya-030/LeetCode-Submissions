class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        int n = nums.size();
        long long ans = 1, sum = 0, temp = 0, i = 0, j = 0;
        while(j < n) {
            sum += nums[j];
            mp[nums[j]]++;
            temp = (j-i+1)*nums[j]-sum;
            while(temp > k && i<=j) {
                sum -= nums[i];
                mp[nums[i]]--;
                temp -= (nums[j]-nums[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};