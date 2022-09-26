#include <bits/stdc++.h>
using namespace std;

// topological sort means linear ordering of values such that if there is an edge u -> v,
// u appears before v in that ordering.

/**
 *  5 -> 0 <- 4
 *  => 5 4 0
 *  5 -> 0 edge in graph and in array 5 appears before 0,
 *  same for 4 -> 0 edge.
 *  It is applicable only for DAG, Directed Acyclic Graph.
 *  Directed because it tells about the ordering
 *  If cyclic graph, like 2 -> 3 -> 4 ->...2
 *  Array: [2, 3, 4] for edge 4 -> 2, 4 can never appear before 2,
 *  So only applicable for acyclic graph
**/

void topoDFS(int node, stack<int> &topo, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }

    topo.push(node);
}

void topoSort(int v, vector<int> adj[]) {
    stack<int> topo;
    vector<int> vis(v + 1, 0);

    for (int i = 0; i <= v; i++) {
        if (!vis[i]) topoDFS(i, topo, vis, adj);
    }

    while (!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
    }
}

int main() {
    int v = 5;
    vector<int> adj[v + 1] = {
        {},
        {},
        {3},
        {1},
        {0, 1},
        {0, 2}
    };

    topoSort(v, adj);
}