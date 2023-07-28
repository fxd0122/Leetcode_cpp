#include <cstdlib>
#include <string>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    int direction[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        // vector<vector<bool>> visted(matrix.size(), vector(matrix[0].size(), false));
        bool ans = false;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
                ans = ans || dfs(matrix, visited, i, j, word, 0);
            }
        } 
        return ans;
    }
    bool dfs(vector<vector<char>>& matrix,vector<vector<bool>>& visited,int x,int y,string& word,int index){
        visited[x][y] = true;
        if(matrix[x][y] != word[index]){
            visited[x][y] = false;
            return false;
        }
        if(index == word.size()-1){
            visited[x][y] = false;
            return true;
        }
        bool ans = false;
        for(int i=0; i<4; i++){
            int new_x = x+direction[i][0];
            int new_y = y+direction[i][1];
            if(new_x<0||new_x>=matrix.size()||new_y<0||new_y>=matrix[0].size()){
                continue;
            }
            if(!visited[new_x][new_y]){
                ans = ans || dfs(matrix, visited, new_x, new_y, word, index+1);
            }
        }
        visited[x][y] = false;
        return ans;
    }
};