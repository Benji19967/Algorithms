// Depth first search on a connected graph. Ignoring edge weights here.
// Time complexity: O(V+E)
// Compile: g++ dfs_test.cpp dfs.cpp

#include "dfs.h"

// Enter number of Vertices and Edges followed by E lines of u v w.
/*
5 7
0 1 2
0 3 7
0 2 6
1 3 3
1 4 6
2 4 1
3 4 5
*/

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    vector<vii> AdjList(V);
    
    vi dfs_num(V, -1); // Initially all vertices are UNVISITED

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }

    dfs(0, AdjList, dfs_num);
}