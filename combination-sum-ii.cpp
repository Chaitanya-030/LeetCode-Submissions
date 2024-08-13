class Solution {

    // private:
    // void solve(vector<int>& arr, int n, int target, vector<vector<int>>& ans, int ind, vector<int> ds){
    //     if(target < 0) return;

    //     if(ind >= n){
    //         if(target == 0){
    //             ans.push_back(ds);
    //         }
    //         return;
    //     }

    //     ds.push_back(arr[ind]);
    //     target -= arr[ind];
    //     solve(arr, n, target, ans, ind+1, ds);

    //     ds.pop_back();
    //     target += arr[ind];
        

    //     while(ind+1 < n && arr[ind] == arr[ind+1]) ind++;
    //     solve(arr, n, target, ans, ind+1, ds);
    // }
public:
    void solve(vector<int>& arr, int curr, int target, vector<vector<int>>& ans, int ind, vector<int>& temp) {
        if(curr > target) return;
        if(ind >= arr.size()) {
            if(curr == target) {
                ans.push_back(temp);
            }
            return;
        }

        curr += arr[ind];
        temp.push_back(arr[ind]);
        solve(arr, curr, target, ans, ind+1, temp);

        curr -= arr[ind];
        temp.pop_back();
        // imp to avoid duplicates
        while(ind+1 < arr.size() && arr[ind] == arr[ind+1]) ind++;
        solve(arr, curr, target, ans, ind+1, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, 0, target, ans, 0, temp);
        return ans;
    }
};