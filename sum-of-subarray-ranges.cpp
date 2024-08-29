class Solution {
public:
    vector<int> PGE(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> PSE(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++) {
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NGE(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, n);
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NSE(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, n);
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        vector<int> nse = NSE(nums);
        vector<int> pse = PSE(nums);
        vector<int> nge = NGE(nums);
        vector<int> pge = PGE(nums);

        long long largest=0, smallest=0;
        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long left1 = i - pge[i];
            long long right1 = nge[i] - i;
            largest += (left*right*nums[i]);
            smallest += (left1*right1*nums[i]);
        }
        return abs(largest-smallest);
    }
};