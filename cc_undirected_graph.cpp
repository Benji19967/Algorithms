// Finding connected components in an unidrected graph.
// Here we'll run dfs on each connected component until we've visited all vertices.
// Time complexity: O(E + V)
// Compile: g++ cc_undirected_graph.cpp dfs.cpp

#include "dfs.h"

// Enter number of Vertices and Edges followed by E lines of u v w. Here edge weight will be ignored.
/*
9 7
0 1 1
1 2 1
1 3 1
2 3 1
3 4 1
6 7 1
6 8 1
*/

int main () {
    int V, E;
    cin >> V;
    cin >> E;

    vector<vii> AdjList(V);
    
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }

    vi dfs_num(V, UNVISITED);

    int numCC = 0;
    for(int i = 0; i < V; i++) {            
        if(dfs_num[i] == UNVISITED) {       // Found an unexplored component.
            printf("CC %d: ", ++numCC);
            dfs(i, AdjList, dfs_num);       // Marks all vertices part of that component as visited.
            printf("\n");
        }
    }
}
