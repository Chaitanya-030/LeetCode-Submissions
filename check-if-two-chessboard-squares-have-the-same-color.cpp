class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        if(c1[0] == 'a' || c1[0] == 'c' || c1[0] == 'e' || c1[0] == 'g') {
            if(c2[0] == 'a' || c2[0] == 'c' || c2[0] == 'e' || c2[0] == 'g') {
                if((c1[1]-'0')%2 == (c2[1]-'0')%2) return 1;
            }
            else {
                if((c1[1]-'0')%2 != (c2[1]-'0')%2) return 1;
            }
        }
        else {
            if(c2[0] == 'a' || c2[0] == 'c' || c2[0] == 'e' || c2[0] == 'g') {
                if((c1[1]-'0')%2 != (c2[1]-'0')%2) return 1;
            }
            else {
                if((c1[1]-'0')%2 == (c2[1]-'0')%2) return 1;
            }
        }
        return 0;
    }
};