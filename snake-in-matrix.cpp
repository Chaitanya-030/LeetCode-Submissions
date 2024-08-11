class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& v) {
        int i = 0, j = 0;
        for(int k=0;k<v.size();k++) {
            if(v[k] == "RIGHT") j++;
            else if(v[k] == "LEFT") j--;
            else if(v[k] == "DOWN") i++;
            else i--;
        }
        return i*n + j;
    }
};