class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);
        }
        for(int j=0; j<n; j++){
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m-1, j);
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]) ans.push_back({i, j});
            }
        }
        return ans;
    }
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visit, int x, int y){
        if(visit[x][y]) return ;
        visit[x][y] = true;
        for(int i=0; i<4; i++){
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if(next_x<0||next_x>=heights.size()||next_y<0||next_y>=heights[0].size()) continue;
            if(heights[x][y] > heights[next_x][next_y]) continue;
            dfs(heights, visit, next_x, next_y);
        }
    }
};