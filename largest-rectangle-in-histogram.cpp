class Solution {
public:
    // vector<int> nextsmallerright(vector<int>& heights, int n) {
    //     vector<int> ans(n);
    //     stack<int> st;
    //     st.push(-1);
    //     for(int i=n-1;i>=0;i--) {
    //         while(st.top() != -1 && heights[st.top()] >= heights[i]) {
    //             st.pop();
    //         }
    //         ans[i] = st.top();
    //         st.push(i);
    //     }

    //     return ans;
    // }

    // vector<int> nextsmallerleft(vector<int>& heights, int n) {
    //     vector<int> ans(n);
    //     stack<int> st;
    //     st.push(-1);
    //     for(int i=0;i<n;i++) {
    //         while(st.top() != -1 && heights[st.top()] >= heights[i]) {
    //             st.pop();
    //         }
    //         ans[i] = st.top();
    //         st.push(i);
    //     }

    //     return ans;
    // }

    vector<int> nextsmallerright(vector<int>& heights, int n) {
        vector<int> ans(n, n);
        stack<int> st;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextsmallerleft(vector<int>& heights, int n) {
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0;i<n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n), left(n);

        right = nextsmallerright(heights, n);
        left  = nextsmallerleft(heights, n);

        int area = INT_MIN;
        for(int i=0;i<n;i++) {
            area = max(area, (right[i] - left[i] - 1)*heights[i]);
        }
        
        return area;
    }
};