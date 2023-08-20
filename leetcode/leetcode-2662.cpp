class Solution {
    using P = pair<int, int>;
private:
    vector<vector<P>> adjLst; // 邻接表
    map<P, int> mp;
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        mp[make_pair(start[0], start[1])] = 0;
        for(auto p : specialRoads){ // 顶点映射
            auto p1 = make_pair(p[0], p[1]);
            auto p2 = make_pair(p[2], p[3]);
            if(mp.find(p1) == mp.end()) mp[p1] = mp.size();
            if(mp.find(p2) == mp.end()) mp[p2] = mp.size();
        } 
        if(mp.find(make_pair(target[0],target[1]))==mp.end()) mp[make_pair(target[0],target[1])]=mp.size();
        // 添加边
        int num_vertex = mp.size();
        this->adjLst.resize(num_vertex);
        for(int i=0; i<specialRoads.size(); i++){
            auto p1 = make_pair(specialRoads[i][0], specialRoads[i][1]);
            auto p2 = make_pair(specialRoads[i][2], specialRoads[i][3]);
            adjLst[mp[p1]].push_back(make_pair(mp[p2], specialRoads[i][4]));
            for(int j=0; j<specialRoads.size(); j++){
                if(i == j) continue;
                auto p3 = make_pair(specialRoads[j][2], specialRoads[j][3]);
                int dist = abs(p3.first - p1.first) + abs(p3.second - p1.second);
                adjLst[mp[p3]].push_back(make_pair(mp[p1], dist));
            }
            int dist = abs(p1.first - start[0]) + abs(p1.second -start[1]);
            adjLst[0].push_back(make_pair(mp[p1], dist));
            dist = abs(p2.first - target[0]) + abs(p2.second - target[1]);
            adjLst[mp[p2]].push_back(make_pair(mp[make_pair(target[0], target[1])], dist));
        }
        int dist = abs(start[0]-target[0]) + abs(start[1]-target[1]);
        adjLst[0].push_back(make_pair(mp[make_pair(target[0], target[1])], dist));
        return dijkstra(0, mp[make_pair(target[0], target[1])]);
    }
    int dijkstra(int start, int end){
        int num_vertex = mp.size();
        vector<bool> st(num_vertex, false);
        vector<int> dist(num_vertex, INT_MAX);
        st[start] = true;
        dist[start] = 0;
        int prev = start;
        for(int i=0; i<num_vertex-1; i++){
            for(auto p : adjLst[prev]){
                int nxt = p.first;
                int dis = p.second;
                if(!st[nxt] && dist[prev] + dis < dist[nxt]) {
                    dist[nxt] = dist[prev] + dis;
                }
            }
            int pivot = -1;
            int min_dist = INT_MAX;
            for(int i = 0; i < num_vertex; i++) {
                if(!st[i]) {
                    if(dist[i] < min_dist) {
                        min_dist = dist[i];
                        pivot = i;
                    }
                }
            }
            //add
            st[pivot] = true;
            prev = pivot;
        }
        return dist[end];
    }
};