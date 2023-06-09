//
//  graph.hpp
//  Graph_Algorithm
//
//  Created by fxd on 2023/7/1.
//

#ifndef GRAPH
#define GRAPH

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <vector>
#include <queue>

const int MAXV = 100;
const int INF = INT_MAX;

struct GRAPH_NODE{
    int index;
    int w;
    GRAPH_NODE(int idx, int weight){
        index = idx;
        w = weight;
    }
};

using node = GRAPH_NODE;


namespace matrix{

template<typename T>
class Graph{
public:
    Graph(bool Direction){
        isDirection = Direction;
        std::fill(G[0], G[0]+MAXV*MAXV, INF);
    }
    
    int change(T name){
        if(name2Index.find(name)!=name2Index.end()){
            return name2Index[name];
        }
        else{
            name2Index[name] = name2Index.size();
            index2Name[name2Index[name]] = name;
            return name2Index[name];
        }
    }
    
    void addEdge(T name1, T name2, int w){
        int idx1 = change(name1);
        int idx2 = change(name2);
        if(isDirection){
            G[idx1][idx2] = w;
            G[idx2][idx1] = w;
        }
        else{
            G[idx1][idx2] = w;
        }
    }
    
    void DFS(int u, int depth){
        vis[u] = true;
        std::cout << index2Name[u] << " ";
        for(int i=0; i<name2Index.size(); i++){
            if(!vis[i] && G[u][i] != INF){
                DFS(i, depth+1);
            }
        }
    }
    
    void DFSTrava(){
        std::fill(vis, vis+MAXV, false);
        for(int u=0; u<name2Index.size(); u++){ //图遍历对所有节点都需要遍历
            if(!vis[u]){
                DFS(u, 1);
            }
        }
    }
    
    void BFS(int u){
        std::queue<int> q;
        q.push(u);
        vis[u] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v=0; v<name2Index.size(); v++){
                if(!vis[v] && G[u][v] != INF){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    
    void BFSTrava(){
        std::fill(vis, vis+MAXV, false);
        for(int u=0; u<name2Index.size(); u++){
            if(!vis[u]){
                BFS(u);
            }
        }
    }
    
    void dijkstra(T s, int* pre){
        std::fill(dis, dis+MAXV, INF);
        std::fill(vis, vis+MAXV, false);
        dis[name2Index[s]] = 0;
        for(int i=0; i<name2Index.size(); i++){
            int u=-1, min_dis = INF;
            for(int j=0; j<name2Index.size(); j++){
                if(!vis[j] && dis[j]<min_dis){
                    u = j;
                    min_dis = dis[j];
                }
            }
            if(u == -1) return ;
            vis[u] = true;
            for(int v=0; v<name2Index.size(); v++){
                if(!vis[v] && G[u][v] != INF && dis[u] + G[u][v] < dis[v]){
                    dis[v] = dis[u] + G[u][v];
                    pre[v] = u;
                }
            }
        }
    }
    
    void getShortPath(T s, T d){
        int pre[MAXV];
        dijkstra(s, pre);
        for(int i=0; i<name2Index.size(); i++){
            std::cout << dis[i] << " ";
        }
        std::cout << "\nThe shortest path is: ";
        std::stack<int> my_stack;
        int temp = name2Index[d];
        my_stack.push(temp);
        while(temp != name2Index[s]){
            temp = pre[temp];
            my_stack.push(temp);
        }
        while(!my_stack.empty()){
            std::cout<< index2Name[my_stack.top()] << " ";
            my_stack.pop();
        }
        std::cout << "\nThe cost is: "<< dis[name2Index[d]] << std::endl;
    }
    
    void floyd(T s, T d){// DP
        int n = name2Index.size();
        int floyd_dis[MAXV][MAXV];
        std::fill(floyd_dis[0], floyd_dis[0]+MAXV*MAXV, INF);
        for(int i=0; i<n; i++){ // 初始化
            for(int j=0; j<n; j++){
                floyd_dis[i][j] = G[i][j];
            }
        }
        for(int i=0; i<n; i++) floyd_dis[i][i] = 0;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(floyd_dis[i][k]!=INF&&floyd_dis[k][j]!=INF&&floyd_dis[i][k]+floyd_dis[k][j]<floyd_dis[i][j]){
                        floyd_dis[i][j] = floyd_dis[i][k]+floyd_dis[k][j];
                    }
                }
            }
        }
        int distance = floyd_dis[name2Index[s]][name2Index[d]];
        std::cout<<"The cost of path "<<s<<" to "<<d<<" is : "<<distance<<std::endl;
    }

    int prim(T s){
        int ans = 0;
        std::fill(dis, dis+MAXV, INF); // 未访问的节点到已经访问节点集合的距离
        std::fill(vis, vis+MAXV, false);
        dis[name2Index[s]] = 0;
        for(int i=0; i<name2Index.size(); i++){
            int u = -1, min_dis = INF;
            for(int j=0; j<name2Index.size(); j++){ // 找最小边
                if(!vis[j] && dis[j]<min_dis){
                    u = j;
                    min_dis = dis[j];
                }
            }
            if(u == -1) return -1;
            vis[u] = true;
            ans += dis[u];
            for(int v=0; v<name2Index.size(); v++){ // 更新
                if(!vis[v]&&G[u][v]!=INF&&G[u][v]<dis[v]){
                    dis[v] = G[u][v];
                }
            }
        }
        return ans;
    }
    
    void get(){
        std::cout << isDirection << std::endl;
    }
    
    
    
    
private:
    std::map<T, int> name2Index;
    std::map<int, T> index2Name;
    int G[MAXV][MAXV];
    int dis[MAXV];
    bool vis[MAXV] = {false};
    bool isDirection;
};

}


namespace linkL{

template<typename  T>
class Graph{
public:
    Graph(bool is_derected): is_unDirected(is_derected){}
    int change(T name){
        if(name2Index.find(name)!=name2Index.end()){
            return name2Index[name];
        }
        else{
            name2Index[name] = name2Index.size();
            index2Name[name2Index[name]] = name;
//            G[name2Index[name]][name2Index[name]] = 0;
            return name2Index[name];
        }
    }
    
    void addEdge(T s, T d, int w){
        int idx1 = change(s);
        int idx2 = change(d);
        node temp1(idx2, w);
        node temp2(idx1, w);
        if(is_unDirected){
            adjL[idx1].push_back(temp1);
            adjL[idx2].push_back(temp2);
        }
        else{
            adjL[idx1].push_back(temp1);
        }
    }
    
    void DFS(int u, int depth){
        vis[u] = true;
        std::cout << index2Name[u] << " ";
        for(int i=0; i<adjL[u].size(); i++){
            if(!vis[adjL[u][i].index]){
                DFS(adjL[u][i].index, depth+1);
            }
        }
    }
    
    void DFSTrave(){
        std::fill(vis, vis+MAXV, false);
        for(int i=0; i<name2Index.size(); i++){
            if(!vis[i]){
                DFS(i, 1);
            }
        }
    }
    
    void BFS(int u){
        std::queue<int> q;
        q.push(u);
        vis[u] = true;
        std::cout<<index2Name[u]<<" ";
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i=0; i<adjL[temp].size(); i++){
                if(!vis[adjL[u][i].index]){
                    q.push(adjL[u][i].index);
                    std::cout<<index2Name[adjL[u][i].index]<<" ";
                    vis[adjL[u][i].index] = true;
                }
            }
        }
    }
    
    void BFSTrave(){
        std::fill(vis, vis+MAXV, false);
        for(int i=0; i<name2Index.size(); i++){
            if(!vis[i]){
                BFS(i);
            }
        }
    }
    
    void dijsktra(int s, int* pre){
        std::fill(vis, vis+MAXV, false);
        std::fill(dis, dis+MAXV, INF);
        dis[s] = 0;
        for(int i=0; i<name2Index.size(); i++){
            int u=-1, min_dis = INF;
            for(int j=0; j<name2Index.size(); j++){
                if(!vis[j] && dis[j]<min_dis){
                    u = j;
                    min_dis = dis[j];
                }
            }
            if(u==-1) return;
            vis[u] = true;
            for(int v=0; v<adjL[u].size(); v++){
                if(!vis[adjL[u][v].index] && dis[u]+adjL[u][v].w < dis[adjL[u][v].index]){
                    dis[adjL[u][v].index] = dis[u] + adjL[u][v].w;
                    pre[adjL[u][v].index] = u;
                }
            }
        }
    }
    
    void getShortPath(T s, T d){
        int idx_start = name2Index[s];
        int idx_end = name2Index[d];
        int pre[MAXV];
        dijsktra(idx_start, pre);
        for(int i=0; i<name2Index.size(); i++){
            std::cout << dis[i] << " ";
        }
        std::cout << "\nThe shortest path is: ";
        std::stack<int> my_stack;
        my_stack.push(idx_end);
        while(idx_end != idx_start){
            idx_end = pre[idx_end];
            my_stack.push(idx_end);
        }
        while(!my_stack.empty()){
            std::cout<< index2Name[my_stack.top()] << " ";
            my_stack.pop();
        }
        std::cout << "\nThe cost is: "<< dis[name2Index[d]] << std::endl;
    }

    bool Bellman_Ford(int s){
        std::fill(dis, dis+MAXV, INF);
        dis[s] = 0;
        for(int i=0; i<name2Index.size()-1; i++){
            int flag = 0;
            for(int u=0; u<name2Index.size(); u++){
                for(int j=0; j<adjL[u].size(); j++){
                    int v = adjL[u][j].index;
                    int w = adjL[u][j].w;
                    if(dis[u] +  w < dis[v]){
                        dis[v] = dis[u] + w;
                        flag = 1;
                    }
                }
            }
            if(!flag) {
                return true;
                break;
            }
        }
        for(int u=0; u<name2Index.size(); u++){
            for(int j=0; j<adjL[u].size(); j++){
                int v = adjL[u][j].index;
                int w = adjL[u][j].w;
                if(dis[u] + w < dis[v]){
                    return false;
                }
            }
        }
        return true;
    }
    
    void getBellmanFordRes(T s, T t){
        int start_idx = name2Index[s];
        int end_idx = name2Index[t];
        bool noneCir = Bellman_Ford(start_idx);
        for(int i=0; i<name2Index.size(); i++){
            std::cout << dis[i] << " ";
        }
        std::cout<<"\nThe short cost from "<<s<<" to "<<t<<" is: "<<dis[end_idx]<<std::endl;
        if(!noneCir){
            std::cout<<"negative loop!\n";
        }
    }
    
    bool SPFA(int s){
        int cnt[MAXV] = {0};
        std::fill(dis, dis+MAXV, INF);
        std::fill(vis, vis+MAXV, false);
        std::queue<int> q;
        q.push(s);
        vis[s] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vis[u] = false;
            for(int j=0; j<adjL[u]; j++){
                int v = adjL[u][j].index;
                int w = adjL[u][j].w;
                if(dis[u]+w<dis[v]){
                    dis[v] = dis[u] + w;
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = true;
                        cnt[v] += 1;
                        if(cnt[v]>=name2Index.size()){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    
    void getSPFARes(T s, T t){
        int start_idx = name2Index[s];
        int end_idx = name2Index[t];
        bool noneCir = Bellman_Ford(start_idx);
        for(int i=0; i<name2Index.size(); i++){
            std::cout << dis[i] << " ";
        }
        std::cout<<"\nThe short cost from "<<s<<" to "<<t<<" is: "<<dis[end_idx]<<std::endl;
        if(!noneCir){
            std::cout<<"negative loop!\n";
        }
    }

        int prim(T s){
        int ans = 0;
        std::fill(vis, vis+MAXV, false);
        std::fill(dis, dis+MAXV, INF);
        vis[s] = true;
        for(int i=0; i<name2Index.size(); i++){
            int u=-1, min_dis = INF;
            for(int j=0; j<name2Index.size(); j++){
                if(!vis[j] && min_dis<dis[j]){
                    u = j;
                    min_dis = dis[j];
                }
            }
            if(u == -1) return -1;
            vis[u] = true;
            ans += min_dis;
            for(int j=0; j<adjL[u].size(); j++){
                int v = adjL[u][j].index;
                int w = adjL[u][j].w;
                if(!vis[v] && w < dis[v]){
                    dis[v] = w;
                }
            }
        }
        return ans;
    }
    
    

private:
    bool is_unDirected; // true: 无向图，false: 有向图
    bool vis[MAXV];
    int dis[MAXV];
    std::vector<node> adjL[MAXV];
    std::map<T, int> name2Index;
    std::map<int, T> index2Name;
};

}
#endif
