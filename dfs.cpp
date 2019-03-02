#include "dfs.h"

void dfs(int u, vector<vii> &AdjList, vi &dfs_num) {    // Initially dfs_num[i] == UNIVISTED for all i.
    dfs_num[u] = VISITED;
    cout << u << " ";
    for(int i = 0; i < (int)AdjList[u].size(); i++) {   
        ii v = AdjList[u][i];                           // v is a (neighbour, weight) pair. Here I ignore the weight.
        if(dfs_num[v.first] == UNVISITED) {             // To avoid cycles.
            dfs(v.first, AdjList, dfs_num);             // Recursively visit neighbours of u.
        }
    }
}