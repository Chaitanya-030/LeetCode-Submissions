class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int cnt = 0;
        while(j < n) {
            sum += nums[j];
            while(sum > k) {
                sum -= nums[i];
                i++;
            }
            cnt++;
            j++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // will not work for negative values
        // int x = solve(nums, goal);
        // int y = solve(nums, goal-1);
        // return x - y;

        int i = 0, j = 0;
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        vector<int> pre(n, 0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++) pre[i] = pre[i-1] + nums[i];
        int cnt = 0;
        for(int i=0;i<n;i++) {
            cnt += mp[pre[i] - goal]; // mp[0] = 1, mp[1] = 1, mp[1] = 2, mp[2] = 1, mp[2] = 2, mp[3] = 1 
            mp[pre[i]]++;
        }
        return cnt;
    }
};