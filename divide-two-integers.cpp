class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;

        long long int divid = abs(dividend);
        long long int divis = abs(divisor);

        int cnt = 0;
        long long int t = divis;

        while(t <= divid) {
            cnt++;
            t += divis;
        }

        // cout<<cnt<<endl;
        if(cnt == 0) return cnt;
        
        int a = dividend < 0;
        int b = divisor < 0;
        if(a^b) return -(cnt);
        // cout<<"x"<<endl;
        return cnt;
    }
};