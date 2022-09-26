#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis) {
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto i : adj[node]) {
        if (!vis[i]) {
            if (checkCycle(i, adj, vis, dfsVis)) return true;
        }
        else if (dfsVis[i]) return true;
    }
    dfsVis[node] = 0;
    return false;
}

bool cycleDFS(int v, vector<int> adj[]) {
    vector<int> vis(v + 1, 0), dfsVis(v + 1, 0);

    for (int i = 1; i <= v; i++) {
        if (!vis[i]) if (checkCycle(i, adj, vis, dfsVis)) return true;
    }
    return false;
}

int main() {
    int v = 2;
    vector<int> adj[v + 1] = {
        {},
        {2},
        {1}
    };

    if (cycleDFS(v, adj)) cout << "Cyclic\n";
}
