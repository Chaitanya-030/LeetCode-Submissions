class Solution {
public:
    int check(long long mid, vector<int>& start, int d) {
        long long prev = start[0];
        for(int i=1;i<start.size();i++) {
            long long nxt = max(prev+mid, (long long)start[i]);
            long long x = start[i] + d;
            if(nxt > x) return 0;
            prev = nxt;
        }
        return 1;
    }

    int maxPossibleScore(vector<int>& start, int d) {
        int n = start.size();
        sort(start.begin(), start.end());
        long long low = 0, high = LLONG_MAX;
        long long ans = 0;

        while(low <= high) {
            long long mid = low + (high - low)/2;
            if(check(mid, start, d)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};