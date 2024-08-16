class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        map<int, int> mp;
        for(auto it : nums) mp[it]++;

        if(mp.size() == 1) return 0;

        auto it1 = mp.begin();
        auto it2 = ++it1;
        it1--;
        int ans = INT_MIN;
        // cout<<it1->first<<" "<<it2->first<<endl;
        while(it2 != mp.end()) {
            ans = max(ans, it2->first - it1->first);
            it1++;
            it2++;
        }
        return ans;
    }
};