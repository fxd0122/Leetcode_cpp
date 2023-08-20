class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            if(!visit[0][i] && board[0][i] == 'O') {
                visit[0][i] = true;
                dfs(board, visit, 0, i);
            }
            if(!visit[m-1][i] && board[m-1][i] == 'O'){
                visit[m-1][i] = true;
                dfs(board, visit, m-1, i);
            } 
        }
        for(int i=1; i<m-1; i++){
            if(!visit[i][0] && board[i][0] == 'O'){
                visit[i][0] = true;
                dfs(board, visit, i, 0);
            }
            if(!visit[i][n-1] && board[i][n-1] == 'O'){
                visit[i][n-1] = true;
                dfs(board, visit, i, n-1);
            } 
        }

        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(board[i][j] == 'O' && !visit[i][j]) board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y){
        // visit[x][y] = true;
        for(int i=0; i<4; i++){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x<0||next_x>=grid.size()||next_y<0||next_y>=grid[0].size()) continue;
            if(!visit[next_x][next_y] && grid[next_x][next_y] == 'O'){
                visit[next_x][next_y] = true;
                dfs(grid, visit, next_x, next_y);
            }
        }
    }
};