#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXV = 110;
const int MAXE = 10010;

struct edge
{
    int u, v;
    int cost;
} E[MAXE];

bool cmp(edge& a, edge& b){
    return a.cost < b.cost;
}

int father[MAXV]; // 并查集
int findFather(int x){
    int a = x;
    while(x != father[x]){
        x = father[x];
    }

    // 路径压缩
    while(a != father[a]){
        int temp = a;
        a = father[a];
        father[temp] = x;
    }
    return x;
}

int kruskal(int &n, int &m){
    int ans = 0, num_Edge = 0;
    for(int i=0; i<m; i++){
        father[i] = i;
    }
    sort(E, E+m, cmp);
    for(int i=0; i<m; i++){
        int father_U = findFather(E[i].u);
        int father_V = findFather(E[i].v);
        if(father_U != father_V){
            father[father_V] = father_U;
            ans += E[i].cost;
            num_Edge += 1;
            if(num_Edge == n-1) break;
        }
    }
    if(num_Edge != n-1) return -1; // 不连通
    else return ans;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
    }
    int ans = kruskal(n, m);
    printf("%d\n", ans);
    return 0;
}