class Solution {
public:
    int count(int mid, vector<int>& nums) {
        int cnt = 0, j = 0, n = nums.size();
        for(int i=0;i<n;i++) {
            while(j < n && nums[j] - nums[i] <= mid) j++;
            cnt += (j-i-1);
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = nums[n-1] - nums[0];
        // int ans = -1;
        while(low < high) {
            int mid = low + (high - low)/2;
            if(count(mid, nums) < k) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};