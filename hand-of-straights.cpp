class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int sz) {
        int n = hand.size();
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for(auto it : hand) mp[it]++;

        for(int i=0;i<n;i++) {
            if(mp[hand[i]] != 0) {
                for(int j=0;j<sz;j++) {
                    int val = hand[i] + j;
                    if(mp[val] == 0) return 0;

                    mp[val]--;
                }
            }
        }

        return 1;
    }
};