/** author: kicker
*   created: 13-08-2022 15:21
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    // n: number of vertex
    // m: number of edges

    cin >> n >> m;
    // for unweighted graph
    // vector<int> adj[n + 1];

    // for weighted graph
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i <= n; i++) {
    	int u, v, dir, wt;
    	cin >> u >> v >> wt;

    	// For directed graph
    	// cin >> dir;
    	// if (dir) adj[v].push_back(u);

    	adj[u].push_back({v, wt});
    	adj[v].push_back({u, wt});
    }

    for (int i = 0; i <= n; i++) {
    	for (int j = 0; j < adj[i].size(); j++) {
    		cout << adj[i][j].first << " " << adj[i][j].second << " ";
    	}
    	cout << endl;
    }
}