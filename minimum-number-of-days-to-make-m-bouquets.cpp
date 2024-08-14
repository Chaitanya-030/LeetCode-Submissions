class Solution {
public:
    int check(vector<int>& arr, int mid, int m, int k) {
        int cnt = 0, ans = 0;
        for(auto it : arr) {
            if(it <= mid) {
                cnt++;
            }
            else {
                cnt= 0;
            }
            
            if(cnt == k) {
                ans++;
                cnt = 0;
            }
        }

        return ans >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int n = arr.size();
        if(n/k < m) return -1;

        int low = 0, high = INT_MAX;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(arr, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};