class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(1) {
            int sum = 0;
            while(n) {
                int dig = n%10;
                sum += (dig*dig);
                n /= 10;
            }

            if(sum==1) return 1;
            if(st.find(sum)!=st.end()) return 0;
            st.insert(sum);

            n=sum;
        }
    }
};