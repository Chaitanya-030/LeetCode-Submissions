class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stack<string> st;
        int n = s.size();
        string temp = "";
        for(int i=0;i<n;i++) {
            if(s[i] == ' ') {
                st.push(temp);
                temp = "";
                continue;
            }
            temp += s[i];
        }
        st.push(temp);

        // cout<<n<<" "<<st.size()<<endl;

        if(pattern.size() != st.size()) return 0;

        // while(!st.empty()) {
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }

        int m = pattern.size();
        int i = m-1;
        map<char, string> mp;
        while(i >= 0 && !st.empty()) {
            if(mp.find(pattern[i]) != mp.end() && mp[pattern[i]] != st.top()) return 0;
            else if(mp.find(pattern[i]) != mp.end()) {
                i--;
                st.pop();
            }
            else {
                mp[pattern[i]] = st.top();
                st.pop();
                i--;
            }
        }
        int x = mp.size();
        set<string> t;
        for(auto it : mp) {
            t.insert(it.second);
        }
        if(x != t.size()) return 0;
        return 1;
    }
};