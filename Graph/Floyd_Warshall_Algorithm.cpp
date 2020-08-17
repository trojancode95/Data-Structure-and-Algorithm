                          Floyd Warshall Algorithm
<------------------------------------------------------------------------------>
--> Used to find shortest path between all pairs of vertices.(in directed as well
    as undirected graphs).
--> Will work even if negative edges are present.
--> Will also be able to detect negative cycles.
--> Time Compleity :- O(V^3).
--> Space Compleity :- O(V^2).


vector<vector<int>> floyd_warshall(int n, vector<vector<pair<int, int>>> &adj) {
	//Matrix of order (n+1)*(n+1)
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, 2e9));
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		for (pair x : adj[i]) {
			int nbr = x.first;
			int wt = x.second;
			dist[i][nb] = w;
		}
	}
	for (int k = 1; k <= n; k++) {
		//kth phase
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
	return dist;
}
