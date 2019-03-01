// Kruskal's algorithm to find the Minimum Spanning Tree of a connected Graph.
// We sort the edges in increasing order and greedily add an edge to the MST if it doesn't create a cycle.
// Checking for cycles can be done in ≈O(1) using the UFDS data structure.
// Time complexity: O(sorting edges + trying to add egde * cost of UF operations) = O(ElogE + E * (≈1)) = O(ElogE) = O(ElogV^2) = O(ElogV)


#include <iostream>
#include <vector>
#include "UnionFind.h"

using namespace std;

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
    cin >> V >> E;

    vector<pair<int, ii> > EdgeList;

    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        EdgeList.push_back(make_pair(w, ii(u, v))); // allows to sort edges by weights
    }

    sort(EdgeList.begin(), EdgeList.end());

    int mst_cost = 0;

    UnionFind UF(V); // Initially all vertices form a separate set
    
    for(int i = 0; i < E; i++) {
        pair<int, ii> front = EdgeList[i];
        if(!UF.isSameSet(front.second.first, front.second.second)) { // Add an edge to the MST if it doesn't create a cycle.
            mst_cost += front.first;
            UF.unionSet(front.second.first, front.second.second);
        }
    }
    cout << mst_cost;
}