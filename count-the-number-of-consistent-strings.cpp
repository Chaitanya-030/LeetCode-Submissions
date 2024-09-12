class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st;
        for(auto it : allowed) st.insert(it);

        int cnt = 0;

        for(auto it : words) {
            int f = 1;
            for(auto x : it) {
                if(st.find(x) == st.end()) {
                    f = 0;
                }
            }
            if(f == 1) cnt++;
        }
        return cnt;
    }
};