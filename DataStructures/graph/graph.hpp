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


namespace matrix{

struct GRAPH_NODE{
    int index;
    int weight;
    GRAPH_NODE(int idx, int w){
        index = idx;
        weight = w;
    }
};

using node = GRAPH_NODE;

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

#endif
