#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
#define inf INT_MAX
#define minf INT_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<<" "; cout<<"\n";
#define printn(v) for(auto x:v) cout<<x<<"\n";
#define F first
#define S second
#define mp make_pair

bool bfs(int **res_capacity, int src, int sink, int n, int *parent) {
	bool visited[n];
	memset(visited, 0, sizeof(visited));
	queue<int>q;
	visited[src] = 1;
	q.push(src);
	bool found_augmented_path = false;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v = 0; v < n; v++) {
			if (!visited[v] && res_capacity[u][v] > 0) {
				parent[v] = u;
				visited[v] = 1;
				q.push(v);
				if (v == sink) {
					found_augmented_path = true;
					break;
				}
			}
		}
	}

	return found_augmented_path;
}

void print_augmented_path(vector<vector<int>>augmented_path) {
	for (int i = 0; i < augmented_path.size(); i++) {
		for (int j = 0; j < augmented_path[i].size(); j++) cout << augmented_path[i][j] << " ";
		cout << endl;
	}
}

int max_flow(int **capacity, int src, int sink, int v) {
	int **residual_capacity = new int*[v];
	for (int i = 0; i < v; i++) residual_capacity[i] = new int[v];
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++)
			residual_capacity[i][j] = capacity[i][j];
	}
	int *parent = new int[1000];
	vector<vector<int>>augmented_path;
	int maxflow = 0;
	while (bfs(residual_capacity, src, sink, v, parent)) {
		vector<int>cur_augmented_path;
		int flow = inf;
		int v = sink;
		while (v != src) {
			cur_augmented_path.pb(v);
			int u = parent[v];
			if (flow > residual_capacity[u][v])
				flow = residual_capacity[u][v];
			v = u;
		}
		cur_augmented_path.pb(src);
		reverse(all(cur_augmented_path));
		augmented_path.pb(cur_augmented_path);
		maxflow += flow;
		v = sink;
		while (v != src) {
			int u = parent[v];
			residual_capacity[u][v] -= flow;
			residual_capacity[v][u] += flow;
			v = u;
		}
	}
	print_augmented_path(augmented_path);
	return maxflow;
}

int32_t main() {
	fastio;
	int v, e;
	cin >> v >> e;
	int **capacity = new int*[v];
	for (int i = 0; i < v; i++) capacity[i] = new int[v];
	for (int i = 0; i < e; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		capacity[u][v] = c;
	}
	cout << max_flow(capacity, 0, 1, v);
}
