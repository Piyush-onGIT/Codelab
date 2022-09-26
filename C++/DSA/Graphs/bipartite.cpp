#include <bits/stdc++.h>
using namespace std;

bool bipBFS(int v, int node, vector<int> adj[], vector<int> &color) {
    color[node] = 0;
    queue<int> q;
    q.push(node);

    while (!q.empty()) {
        int n = q.front(), c = color[n];
        q.pop();

        for (int i : adj[n]) {
            if (color[i] == -1) {
                color[i] = c ^ 1;
                q.push(i);
            }
            else if (color[i] == c) return false;
        }
    }
    return true;
}

bool checkBipBFS(int v, vector<int> adj[]) {
    vector<int> color(v + 1, -1);

    for (int i = 1; i <= v; i++) {
        if (color[i] == -1) {
            if (!bipBFS(v, i, adj, color)) return false;
        }
    }

    return true;
}

bool bipDFS(int node, int parent, vector<int> adj[], vector<int> &color) {
    if (parent == -1) color[node] = 1;
    else if (color[node] == -1) color[node] = color[parent] ^ 1;
    else {
        if (color[node] == color[parent]) return false;
        else return true;
    }

    for (int i : adj[node]) {
        if (!bipDFS(i, node, adj, color)) return false;
    }
    return true;
}

bool checkBipDFS(int v, vector<int> adj[]) {
    vector<int> color(v + 1, -1);

    for (int i = 1; i <= v; i++) {
        if (color[i] == -1) {
            if (!bipDFS(i, -1, adj, color)) return false;
        }
    }
    return true;
}

int main() {
    int v = 8;
    vector<int> adj[v + 1] = {
        {},
        {2},
        {1, 3, 6},
        {2, 4},
        {5, 3},
        {7, 4, 6},
        {2, 5},
        {5, 8},
        {7}
    };

    if (checkBipBFS(v, adj)) cout << "Bipartite BFS\n";
    if (checkBipDFS(v, adj)) cout << "Bipartite DFS\n";
}