#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                ll rem = (ll)target - (ll)nums[i] - (ll)nums[j];
                int low = j+1, high = n-1;
                while(low < high) {
                    if(nums[low] + nums[high] < rem) low++;
                    else if(nums[low] + nums[high] > rem) high--;
                    else {
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++;
                        high--;
                    }
                }
            }
        }

        for(auto it : st) ans.push_back(it);
        return ans;
    }
};