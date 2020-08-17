#include<bits/stdc++.h>
using namespace std;

const int N = 100005, M = 22;
vector<int>graph[N];

void bfs(int src, int n, int &ans) {
	vector<int>dist(n + 1, INT_MAX);
	queue<int>Q;
	Q.push(src);
	dist[src] = 0;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (auto nbr : graph[cur]) {
			if (dist[nbr] == INT_MAX) {
				//Neighbour not visited.
				dist[nbr] = dist[cur] + 1;
				Q.push(nbr);
			}
			//Condition for backedge
			else if (dist[nbr] >= dist[cur]) {
				//Backedge is encountered
				ans = min(ans, dist[nbr] + dist[cur] + 1);
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int ans = n + 1;
	for (int i = 1; i <= n; i++) {
		bfs(i, n, ans);
	}
	if (ans == n + 1) {
		cout << "No cycle" << endl;
	}
	else {
		cout << "Shortest cycle is of length " << ans << endl;
	}
}



int main() {
	solve();
}
