class Solution {
public:
    vector<vector<string>> ans;
    bool isVaild(int row, int col, vector<string>& chessboard, int n){
        for(int i=0; i<row; i++){
            if(chessboard[i][col]=='Q') return false;
        }
        for(int i=row, j=col; i>=0&&j>=0; i--, j--){
            if(chessboard[i][j] == 'Q') return false;
        }
        for(int i=row, j=col; i>=0&&j<n; i--, j++){
            if(chessboard[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtracking(int n, int row, vector<string>& chessboard){
        if(row == n){
            ans.push_back(chessboard);
            return ;
        }
        for(int col=0; col<n; col++){
            if(isVaild(row, col, chessboard, n)){
                chessboard[row][col] = 'Q';
                backtracking(n, row+1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(n, 0, chessboard);
        return ans;
    }
};