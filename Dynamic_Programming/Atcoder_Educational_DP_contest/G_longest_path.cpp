// https://atcoder.jp/contests/dp/tasks/dp_g

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

const int N = 1e5 + 1;
vector<int>gr[N];
int dp[N]; //dp[i] = represents length of longest path starting at node i

int longest_path(int src) {
	if (dp[src] != -1) return dp[src];
	bool leaf_node = 1;
	int best_child = 0;
	for (auto child : gr[src]) {
		leaf_node = 0;
		best_child = max(best_child, longest_path(child));
	}
	return dp[src] = (leaf_node ? 0 : 1 + best_child);
}

int32_t main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		gr[u].pb(v);
	}
	memset(dp, -1, sizeof dp);
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, longest_path(i));
	cout << ans << endl;
}
