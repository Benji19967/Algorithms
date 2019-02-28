/*  - Union-Find Disjoint Sets is a custom Data Structure that allows to efficiently check if an element is part of a set,
      if two elements are part of the same set or to combine to disjoint sets into one.
    - The amortized time complexity of these operations is O(1).
    - We keep track of the parent and the rank for each vertex, the rank being an upper bound on the height of a tree representing a set.
    - Path compression is used in the findSet() operation to allow faster lookup in subsequent calls to the Method.
*/

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

class UnionFind {
    private: vi p, rank;
    public:
        UnionFind(int N) {
            p.assign(N, 0);
            rank.assign(N, 0);
            for(int i = 0; i < N; i++) {
                p[i] = i;
            }
        }

        int findSet(int i) {
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }
        void unionSet(int i, int j) {
            int x = findSet(i);
            int y = findSet(j);

            if(rank[x] > rank[y]) p[y] = x;
            else {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
}