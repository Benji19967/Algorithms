// Breath first search on a connected graph. Ignoring edge weights here.
// Time complexity: O(V+E) using Adjacency List representation, O(V^2) if we used Adjacency Matrix.

// Using distance == INF to check if a vertex is still unvisited.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF numeric_limits<int>::max()

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
    cin >> V >> E;

    vector<vii> AdjList(V);

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }

    int s = 0; // pick source
    
    vi d(V, INF); d[s] = 0;
    queue<int> q; q.push(s);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int i = 0; i < (int)AdjList[u].size(); i++) {
            ii v = AdjList[u][i]; // (v, w)
            if(d[v.first] == INF) { // if distance is INF, the vertex is still unvisited
                q.push(v.first);
                d[v.first] = d[u] + 1;
            }
        }
    }
}