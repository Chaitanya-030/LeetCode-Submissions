class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for(auto it : s) {
            mp[it]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto it :mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while(!pq.empty()) {
            int val = pq.top().first;
            while(val--) {
                ans += pq.top().second;
            }
            pq.pop();
        }

        return ans;
    }
};