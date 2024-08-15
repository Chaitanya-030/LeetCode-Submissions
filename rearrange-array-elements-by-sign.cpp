class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> qp, qn;
        vector<int> ans;
        int n = nums.size();
        int pos = 1;
        for(int i=0;i<n;i++) {
            if(nums[i] > 0) qp.push(nums[i]);
            else qn.push(nums[i]);

            if(pos == 1 && !qp.empty()) {
                ans.push_back(qp.front());
                qp.pop();
                pos = 0;
            }
            else if(pos == 0 && !qn.empty()) {
                ans.push_back(qn.front());
                qn.pop();
                pos = 1;
            }
        }
        while(!qp.empty() || !qn.empty()) {
            if(pos == 1 && !qp.empty()) {
                ans.push_back(qp.front());
                qp.pop();
                pos = 0;
            }
            else if(pos == 1 && qp.empty()) {
                pos = 0;
            }
            if(pos == 0 && !qn.empty()) {
                ans.push_back(qn.front());
                qn.pop();
                pos = 1;
            }
            if(pos == 1 && qn.empty()) {
                pos = 1;
            }
        }
        return ans;
    }
};