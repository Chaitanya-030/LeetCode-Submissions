class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;

        vector<int> right(n, n);
        vector<int> left(n, -1);

        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();

            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        st=stack<int>();

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();

            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++) {
            long long l=i-left[i];
            long long r=right[i]-i;
            long long val=(l%mod*r%mod)%mod;
            ans = (ans + (arr[i]*val)%mod)%mod;
        }
        return ans;
    }
};