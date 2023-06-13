#include<vector>

class UnionFindSet{
private:
    int num_set;
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFindSet(int size){
        num_set = size;
        for(int i=0; i<size; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int node){ // 将节点的父节点指向根节点
        if(node != parent[node]){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unite(int x, int y){
        int root_x = find(x);
        int root_y = find(y);
        if(root_x == root_y) return;
        if(rank[root_x]<rank[root_y]){ // 将高度低的集合并到高度大的集合
            std::swap(root_x, root_y);
        }
        parent[root_y] = root_x;
        if(rank[root_x] == rank[root_y]) rank[root_x] += 1;
        num_set -= 1;
    }

    int getNumSet(){
        return num_set;
    }
};

