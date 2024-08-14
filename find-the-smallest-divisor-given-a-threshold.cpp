class Solution {
public:
    int check(int mid, vector<int>& nums, int val) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += (nums[i]/mid) + (nums[i]%mid!=0);
        }
        return sum <= val;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(mid, nums, threshold)) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};