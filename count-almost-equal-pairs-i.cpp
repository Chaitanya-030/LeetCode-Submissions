class Solution {
public:
    int check(int num1, int num2) {
        string n1 = to_string(num1);
        string n2 = to_string(num2);

        while(n1.size()<n2.size()) n1 = "0" + n1;
        while(n2.size()<n1.size()) n2 = "0" + n2;

        int diff = 0;
        int a=-1, b=-1;
        for(int i=0;i<n1.size();i++) {
            if(n1[i] != n2[i]) {
                diff++;
                if(diff==1) a = i;
                else if(diff==2) b=i;
                else return 0;
            }
        }
        if(diff==2) swap(n1[a], n1[b]);
        return n1==n2;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int num1 = nums[i];
                int num2 = nums[j];

                if(num1==num2 || check(num1,num2)) cnt++;
            }
        }
        return cnt;
    }
};