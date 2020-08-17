#include<bits/stdc++.h>
using namespace std;

const int N = 100005, M = 23;
vector<int>gr[N];
int visited[N];
bool odd_cycle = 0;

void dfs(int cur, int parent, int color) {
	visited[cur] = color;
	for (auto child : gr[cur]) {
		if (visited[child] == 0) {
			dfs(child, cur, 3 - color);
		}
		else if (child != parent && color == visited[child]) {
			// backedge and odd length cycle
			odd_cycle = 1;
		}
	}
	return;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	dfs(1, 0, 1);
	if (odd_cycle)
		cout << "Not Bipartite graph" << endl;
	else
		cout << "Bipartite graph" << endl;
}

int main() {
	solve();
}
