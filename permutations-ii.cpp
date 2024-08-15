class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, int ind) {
        if(ind >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int i=ind;i<nums.size();i++) {
            swap(nums[ind], nums[i]);
            solve(ans, nums, ind+1);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        set<vector<int>> st(ans.begin(), ans.end());
        vector<vector<int>> f_ans;
        for(auto it : st) f_ans.push_back(it);
        return f_ans;
    }
};