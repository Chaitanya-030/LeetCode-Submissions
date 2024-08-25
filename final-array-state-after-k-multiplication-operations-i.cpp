class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int m) {
        int n = nums.size();
        for(int i=0;i<k;i++) {
            int mini = INT_MAX;
            int ind;
            for(int i=0;i<n;i++) {
                if(nums[i] < mini) {
                    mini = nums[i];
                    ind = i;
                }
            }
            nums[ind] *= m;
        }
        return nums;
    }
};