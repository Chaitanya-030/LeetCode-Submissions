class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mp;
        for(auto it : nums) {
            mp[it]++;
            if(mp[it] > 1) ans.push_back(it);
        }
        return ans;
    }
};