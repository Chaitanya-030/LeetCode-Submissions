class Solution {
public:
    int check(vector<vector<char>>& board, int r, int c, char ch) {
        for(int j=0;j<9;j++){
            if(j!=c && board[r][j] == ch) return 0;
        }

        for(int i=0;i<9;i++){
            if(i!=r && board[i][c] == ch) return 0;
        }

        int rt=r-r%3;
        int ct=c-c%3;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(board[i+rt][j+ct] == ch && (i+rt)!=r && (j+ct)!=c) return 0;
            }
        }

        return 1;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] != '.') {
                    if(!check(board,i,j,board[i][j])) return 0;
                }
            }
        }
        return 1;
    }
};