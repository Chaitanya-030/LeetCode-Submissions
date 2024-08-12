class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        int i = 0;
        int f;
        int val = 0;
        while(i < s.size()) {
            char ch = s[i];
            if(ch=='(' || ch=='!' || ch=='|' || ch=='&' || ch=='f' || ch=='t') st.push(ch);
            else if(ch==')') {
                vector<bool> x;
                while(st.top()!='(') {
                    if(st.top()=='f') x.push_back(false);
                    else if(st.top()=='t') x.push_back(true);  
                    st.pop();   
                }
                if(val==0) {
                f=x[0];
                val++;
            }
            st.pop();// removing (
            // if(st.empty()) break;
            char c = st.top();
            st.pop();
            if (c == '&') {
                for (auto it : x) {
                    f &= it;
                }
            }
            else if (c == '!') { 
                f = !x[0]; 
            }
            else if (c == '|') {
                for (auto it : x) {
                    f |= it;
                }
            }
            if(f) st.push('t');
            else st.push('f');
            }
            i++;
        }
        return f;
    }
};