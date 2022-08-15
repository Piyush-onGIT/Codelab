/** author: kicker
*   created: 13-08-2022 23:40
**/
#include <bits/stdc++.h>
using namespace std;

bool cycleDFS(int node, int parent, vector<int> adj[], vector<int> &visited) {
	visited[node] = 1;
	for (auto i : adj[node]) {
		if (i != parent && visited[i]) return true;
		if (!visited[i]) cycleDFS(i, node, adj, visited);
	}
	return false;
}

bool cycleDetection(int v, vector<int> adj[]) {
	vector<int> visited(v + 1, 0);

	for (int i = 1; i <= v; i++) {
		if (cycleDFS(i, -1, adj, visited)) return true;
	}
}

int main() {
    int v = 8;			// number of nodes
	vector<int> adj[v + 1] = {
		{},
		{2},
		{1, 4, 7},
		{5},
		{2, 6},
		{3},
		{4, 7},
		{8, 2, 6},
		{7}
	};

	if (cycleDetection(v, adj)) cout << "Cyclic\n";
}