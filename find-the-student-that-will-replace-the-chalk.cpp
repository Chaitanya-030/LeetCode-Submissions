class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k=k%sum;
        for(int i=0;i<n;i++) {
            k -= chalk[i];
            if(k < 0) return i;
            // if((i+1)%n == 0) i = -1;
        }
        return 0;
    }
};