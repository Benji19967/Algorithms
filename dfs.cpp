// Depth first search of a connected graph. Ignoring edge weights here.
// Time complexity: O(V+E)

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define UNVISITED -1
#define VISITED 1

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

void dfs(int u, vector<vii> &AdjList, vi &dfs_num) {
    dfs_num[u] = VISITED;
    cout << u << " ";
    for(int i = 0; i < (int)AdjList[u].size(); i++) {   
        ii v = AdjList[u][i];                           // v is a (neighbour, weight) pair. Here I ignore the weight
        if(dfs_num[v.first] == UNVISITED) {             // To avoid cycles
            dfs(v.first, AdjList, dfs_num);             // Recursively visit neighbours of u
        }
    }
}

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