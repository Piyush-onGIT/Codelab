/** author: kicker
*   created: 13-08-2022 23:40
**/
#include <bits/stdc++.h>
using namespace std;

// Cycle Detection in undirected graph

bool cycleDFS(int node, int parent, vector<int> adj[], vector<int> &visited) {
	visited[node] = 1;
	for (auto i : adj[node]) {
		if (!visited[i]) {
			if (cycleDFS(i, node, adj, visited)) return true;
		}
		else if (i != parent) return true;
	}
	return false;
}

bool cycleDetectionDFS(int v, vector<int> adj[]) {
	vector<int> visited(v + 1, 0);

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			if (cycleDFS(i, -1, adj, visited)) return true;
		}
	}
	return false;
}

bool cycleBFS(int v, int node, vector<int> adj[], vector<int> &visited) {
	queue<pair<int, int>> q;
	q.push({node, -1});
	visited[node] = 1;

	while (!q.empty()) {
		int n = q.front().first;
		int par = q.front().second;
		q.pop();

		for (int i : adj[n]) {
			if (!visited[i]) {
				q.push({i, n});
				visited[i] = 1;
			}
			else if (i != par) return true;
		}
	}
	return false;
}

bool cycleDetectionBFS(int v, vector<int> adj[]) {
	vector<int> visited(v + 1, 0);

	for (int i = 1; i <= v; i++) {
		if (!visited[i] and cycleBFS(v, i, adj, visited)) return true;
	}
	return false;
}

int main() {
    int v = 2;			// number of nodes
	vector<int> adj[v + 1] = {
		{},
		{2},
		{1}
	};

	if (cycleDetectionDFS(v, adj)) cout << "Cyclic Using DFS\n";
	if (cycleDetectionBFS(v, adj)) cout << "Cyclic Using BFS\n";
}