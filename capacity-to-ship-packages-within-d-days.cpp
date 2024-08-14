class Solution {
public:
    int check(int mid, vector<int>& w, int days) {
        int cnt = 1, sum = 0;
        int n = w.size();
        for(int i=0;i<n;i++) {
            if(w[i] > mid) return 0;
            sum += w[i];
            if(sum > mid) {
                cnt++;
                sum = w[i];
            }
        }
        return cnt <= days;
    }

    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int sum = accumulate(w.begin(), w.end(), 0);
        // cout<<sum<<endl;
        int low = 1, high = sum;
        int ans = -1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(check(mid, w, days)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};