// 19
// 1 2
// 2 4
// 2 5
// 5 6
// 6 7
// 6 8
// 6 9
// 1 3
// 3 10
// 10 17
// 17 18
// 17 19
// 3 11
// 11 12
// 12 13
// 12 14
// 12 15
// 15 16


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
vector<int>gr[N];
int p[N][M];//Parent
int d[N];//depth
int tin[N], tout[N];
int timer;

//O(n)
void dfs(int cur, int par = 0) {
	tin[cur] = ++timer;
	for (auto x : gr[cur]) {
		if (x != par) {
			d[x] = d[cur] + 1;
			dfs(x, cur);
		}
	}
	tout[cur] = timer;
}

//It is just like a dfs
void cal_sparse_table(int cur, int par = 0) {
	p[cur][0] = par;
	for (int j = 1; j < M; j++)
		p[cur][j] = p[p[cur][j - 1]][j - 1];

	for (auto x : gr[cur]) {
		if (x != par)
			cal_sparse_table(x, cur);
	}
}

//Whether u is a ancestor of v or not
bool is_ancestor(int u, int v) {
	return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

//LCA using time in and time out
int lca_using_time(int u, int v) {
	if (is_ancestor(u, v)) return u;
	if (is_ancestor(v, u)) return v;
	for (int i = M - 1; i >= 0; i--) {
		//If p[u][i] is not a ancestor of v , then move to it
		if (!is_ancestor(p[u][i], v)) u = p[u][i];
	}
	return p[u][0];
}

int32_t main() {
	fastio;
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	timer = 0;
	tin[0] = 0; tout[0] = n + 1;//Universal Parent
	//Root as 1
	dfs(1);
	cal_sparse_table(1);
	cout << lca_using_time(9, 15) << endl;
	cout << lca_using_time(18, 15) << endl;
	cout << lca_using_time(15, 15) << endl;
	cout << lca_using_time(11, 16) << endl;
}
