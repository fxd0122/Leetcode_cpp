class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0, graph.size()-1);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, int start, int end){
        if(start == end) ans.push_back(path);
        for(int i=0; i<graph[start].size(); i++){
            path.push_back(graph[start][i]);
            dfs(graph, graph[start][i], end);
            path.pop_back();
        }
    }
};