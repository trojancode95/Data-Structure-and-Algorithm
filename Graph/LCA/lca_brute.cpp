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

const int N = 10005, M = 22;
vector<int>gr[N];
int p[N];//Parent
int d[N];//depth


void dfs(int cur, int par = 0) {
	p[cur] = par;
	for (auto x : gr[cur]) {
		if (x != par) {
			d[x] = d[cur] + 1;
			dfs(x, cur);
		}
	}

}

//Time Complexity : O(n)
int lca_brute(int u, int v) {
	if (u == v) return u;

	//Lets take u to be at more depth
	if (d[u] < d[v]) swap(u, v);

	while (d[u] > d[v]) u = p[u];
	//Now they are at the same level
	while (u != v) {
		u = p[u];
		v = p[v];
	}
	return u;
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
	//Root as 1
	dfs(1);
	for (int i = 1; i < n; i++) cout << i << " " << d[i] << " " << p[i] << endl;
	cout << lca_brute(18, 16) << endl;
	cout << lca_brute(9, 2) << endl;

}
