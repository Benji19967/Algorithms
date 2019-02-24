// Dijkstra's algorithm is used to find the shortest distance to all nodes from a source node in a weighted graph. (SSSP)
// Negative weight cycles cannot be present in the graph. Use Bellman-Ford in that case.
// Time complexity: O(E*logV)

#include <iostream>
#include <queue>

using namespace std;

#define INF numeric_limits<int>::max()

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

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

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        AdjList[u].push_back(ii(v, w));
        AdjList[v].push_back(ii(u, w));
    }

    int s = 0;

    vi dist(V, INF); // intialize distance to infinity
    dist[s] = 0; 

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(s, 0));

    while(!pq.empty()) {
        ii front = pq.top(); pq.pop(); // greedy step: get shortest unvisited node
        int d = front.first;
        int u = front.second;

        if(d > dist[u]) continue; // already explored a path to u that is shorter than the current one

        for(int j = 0; j < (int)AdjList[u].size(); j++) { // explore all neighbours of u
            ii v = AdjList[u][j];
            if(dist[u] + v.second < dist[v.first]) { // relax the edge
                dist[v.first] = dist[u] + v.second;
                pq.push(ii(dist[v.first], v.first));
            }
        }
    }
    for(int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
}