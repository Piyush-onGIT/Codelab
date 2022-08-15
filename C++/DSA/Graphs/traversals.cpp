/** author: kicker
*   created: 13-08-2022 22:21
**/
#include <bits/stdc++.h>
using namespace std;

void bfs(int v, vector<int> adj[]) {
	vector<int> ans;
	vector<int> visited(v + 1, 0);

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			while (!q.empty()) {
				int node = q.front();
				q.pop();
				ans.push_back(node);

				for (auto i : adj[node]) {
					if (!visited[i]) {
						q.push(i);
						visited[i] = 1;
					}
				}
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
}

void recurDFS(int node, vector<int> adj[], vector<int> &ans, vector<int> &visited) {
	ans.push_back(node);
	visited[node] = 1;

	for (auto i : adj[node]) {
		if (!visited[i]) recurDFS(i, adj, ans, visited);
	}
}

void dfs(int v, vector<int> adj[]) {
	vector<int> visited(v + 1, 0);
	vector<int> ans;

	for (int i = 1; i <= v; i++) {
		if (!visited[i]) recurDFS(i, adj, ans, visited);
	}
	
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	int v = 7;			// number of nodes
	vector<int> adj[v + 1] = {
		{},
		{2},
		{1, 4, 7},
		{5},
		{2, 6},
		{3},
		{4, 7},
		{2, 6}
	};

	dfs(v, adj);
}