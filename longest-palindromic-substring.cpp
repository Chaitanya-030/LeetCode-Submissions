class Solution {
public:
    string longestPalindrome(string A) {
        // int n = A.size();
        // if(n < 2) return A;
        
        // int max_len = 1;
        // int start = 0;
        // int low, high;
        
        // for(int i=0;i<n;i++){
        //     int low = i - 1;
        //     int high = i + 1;
        //     while(high < n && A[high] == A[i]) high++;
        //     while(low >= 0 && A[low] == A[i]) low--;
            
        //     while(low >= 0 && high < n && A[low] == A[high]){
        //         low--;
        //         high++;
        //     }
            
        //     int len = high - low - 1;
        //     if(len > max_len){
        //         max_len = len;
        //         start = low + 1;
        //     }
        // }
        
        // return A.substr(start, max_len);

        // int n = A.size();
        // if(n <= 1) return A;

        // int maxi = 1, low = 0, high = 0;
        // int start = 0;
        // for(int i=0;i<n;i++) {
        //     low = i-1, high = i+1;
        //     while(high < n && A[high] == A[i]) high++;
        //     while(low >= 0 && A[low] == A[i]) low--;

        //     while(low >= 0 && high < n && A[low] == A[high]) {
        //         high++;
        //         low--;
        //     }

        //     if(high - low - 1 > maxi) {
        //         maxi = high - low - 1;
        //         start = low + 1;
        //     }
        // }

        // return A.substr(start, maxi);


        int n = A.size();
        if(n <= 1) return A;

        int start = 0;
        int maxi = 1, low = 0, high = 0;
        for(int i=0;i<n;i++) {
            low = i-1, high = i+1;
            while(low >= 0 && A[low] == A[i]) low--;
            while(high < n && A[high] == A[i]) high++;

            while(low >= 0 && high < n && A[low] == A[high]) {
                low--;
                high++;
            }

            if(high - low - 1 > maxi) {
                maxi = high - low - 1;
                start = low+1;
            }
        }

        return A.substr(start, maxi);
    }
};