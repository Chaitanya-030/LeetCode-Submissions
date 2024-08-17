class Solution {
public:
    int addDigits(int num) {
        int sum = 0, rem = 0;
        while(num) {
            rem=num%10;
            sum+=rem;
            num/=10;
        }
        if(sum%10!=sum) return addDigits(sum);
        return sum;
    }
};