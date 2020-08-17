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

const int N = 100005, M = 22;
vector<pair<int, int>>gr[N];
int p[N][M];//Parent
int d[N];//depth
int dis[N];//Sum of weight of the path from root to i

//O(n)
void dfs(int cur, int par = 0) {
	for (auto x : gr[cur]) {
		if (x.F != par) {
			d[x.F] = d[cur] + 1;
			dis[x.F] = dis[cur] + x.S;
			dfs(x.F, cur);
		}
	}
}

//It is just like a dfs
void cal_sparse_table(int cur, int par = 0) {
	p[cur][0] = par;
	for (int j = 1; j < M; j++)
		p[cur][j] = p[p[cur][j - 1]][j - 1];

	for (auto x : gr[cur]) {
		if (x.F != par)
			cal_sparse_table(x.F, cur);
	}
}

//Lets find LCA using depth using Binary lifting
//Time complexity : O(logn)==O(m)
int lca_sparse(int u, int v) {
	if (u == v) return u;

	if (d[u] < d[v]) swap(u, v);
	int diff = d[u] - d[v];
	for (int i = M - 1; i >= 0; i--) {
		if ((diff >> i) & 1) u = p[u][i];
	}
	//After this u and v are on the same depth
	//If v was ancestor of u
	if (u == v) return u;
	for (int i = M - 1; i >= 0; i--) {
		if (p[u][i] != p[v][i]) {
			u = p[u][i];
			v = p[v][i];
		}
	}

	//I am standing on different  nodes and both these u and v are child of lca
	return p[u][0];
}

//Distnace between two nodes : O(M)
int distance(int x, int y) {
	//dis(x,y)=dis(x)+dis(y)-2*dis(lca)
	int lca = lca_sparse(x, y);
	return dis[x] + dis[y] - 2 * dis[lca];
}

int32_t main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].pb({y, w});
		gr[y].pb({x, w});
	}
	//Root as 1
	dfs(1);
	cal_sparse_table(1);
	cout << distance(4, 6) << endl;
	cout << distance(1, 7) << endl;
}
