#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define UNVISITED -1
#define VISITED 1

#ifndef DFS
#define DFS
    void dfs(int u, vector<vii> &AdjList, vi &dfs_num);
#endif 
