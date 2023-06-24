#include <iostream>
#include <algorithm>
using namespace std;

const int MAXV = 1000;
const int INF = 10000000;

int n, m, s;
int d[MAXV];
bool vis[MAXV] = {false};
int G[MAXV][MAXV];

void dijsktra(int s){
    fill(d, d+MAXV, INF);
    d[s] = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j=0; j<n; j++){
            if(!vis[j] && d[j]<MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return ;
        vis[u] = true;
        for(int v=0; v<n; v++){
            if(!vis[v] && G[u][v]!=INF && d[u]+G[u][v]<d[v]){
                d[v] = d[u]+G[u][v];
            }
        }
    }
}

int main(){
    int u, v, w;
    std::cout << "please input n m s\n";
    std::cin >> n >> m >> s;
    fill(G[0], G[0] + MAXV*MAXV, INF);
    for(int i=0; i<m; i++){
        std::cin >> u >> v >> w;
        G[u][v] = w;
    }
    dijsktra(s);
    for(int i=0; i<n; i++){
        std::cout << d[i] << " ";
    }
    return 0;
}