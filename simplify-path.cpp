class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string ans="";
        for(int i=0;i<path.size();i++) {
            if(path[i] == '/') continue;
            string x="";
            while(i < path.size() && path[i] != '/') {
                x += path[i];
                i++;
            }
            if(x == ".") continue;
            else if(x == "..") {
                if(!st.empty()) st.pop();
            }
            else {
                st.push(x);
            }
        }

        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        if(ans == "") return "/";
        return ans;
    }
};