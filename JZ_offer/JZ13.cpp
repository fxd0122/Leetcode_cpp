class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
        if(threshold == 0){
            return 1;
        }
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        dfs(visited, threshold, 0, 0);
        return ans;
    }
private:
    int ans = 0;
    int direction[4][2] = {0,1,1,0,0,-1,-1,0};
    void dfs(vector<vector<bool>>& visited, int threshold, int x, int y){
        visited[x][y] = true;
        ans++;
        for(int i=0; i<4; i++){
            int new_x = x+direction[i][0];
            int new_y = y+direction[i][1];
            if(new_x<0||new_x>=visited.size()||new_y<0||new_y>=visited[0].size()){
                continue;
            }
            if(!visited[new_x][new_y] && getNum(new_x, new_y) <= threshold){
                dfs(visited, threshold, new_x, new_y);
            }
        }
    }
    int getNum(int x, int y){
        int temp = 0;
        while(x>0){
            temp += x%10;
            x = x/10;
        }
        while(y>0){
            temp += y%10;
            y = y/10;
        }
        return temp;
    }
};