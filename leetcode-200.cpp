// dfs 解法
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    ans += 1;
                    visit[i][j] = true;
                    dfs(grid, visit, i, j);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y){
        for(int i=0; i<4; i++){
            int next_x = x+dir[i][0];
            int next_y = y+dir[i][1];
            if(next_x<0||next_x>=grid.size()||next_y<0||next_y>grid[0].size()) continue;
            if(!visit[next_x][next_y] && grid[next_x][next_y] == '1'){
                visit[next_x][next_y] = true;
                dfs(grid, visit, next_x, next_y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visit[i][j] && grid[i][j]=='1'){
                    visit[i][j] = true;
                    ans += 1;
                    bfs(grid, visit, i, j);
                }
            }
        }
        return ans;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visit, int x, int y){
        queue<pair<int, int>> s;
        s.push({x, y});
        while(!s.empty()){
            pair<int, int> temp = s.front();
            s.pop();
            int cur_x = temp.first;
            int cur_y = temp.second;
            for(int i=0; i<4; i++){
                int next_x = cur_x + dir[i][0];
                int next_y = cur_y + dir[i][1];
                if(next_x<0||next_x>=grid.size()||next_y<0||next_y>=grid[0].size()) continue;
                if(!visit[next_x][next_y] && grid[next_x][next_y] == '1'){
                    visit[next_x][next_y] = true;
                    s.push({next_x, next_y});
                }
            }
        }
    }
};

// bfs 解法
