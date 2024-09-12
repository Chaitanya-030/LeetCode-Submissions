class Solution {
public:
    int func(int s, int g)
    {
        int cnt = 0;
        for (int i = 31; i >= 0; i--) {
            int k = s >> i;
            int r = g >> i;
            if ((k & 1) != (r & 1))
                cnt++;
        }
        return cnt;
    }

    int minBitFlips(int start, int goal) {
        return func(start, goal);
    }
};