class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i>=1&&i<m-1&&j>=1&&j<n-1) continue;
                if(!visit[i][j] && grid[i][j]==1){
                    visit[i][j] = true;
                    dfs(grid, visit, i, j);
                }
            }
        }
        int ans = 0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(grid[i][j] == 1 && !visit[i][j]) ans++;
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit, int x, int y){
        for(int i=0; i<4; i++){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x<0||next_x>=grid.size()||next_y<0||next_y>=grid[0].size()) continue;
            if(!visit[next_x][next_y] && grid[next_x][next_y] == 1){
                visit[next_x][next_y] = true;
                dfs(grid, visit, next_x, next_y);
            }
        }
    }
};