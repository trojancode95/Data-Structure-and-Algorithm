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
#define print(v) for(auto x:v) cout<<x<<" "; cout<<endl;
#define printn(v) for(auto x:v) cout<<x<<endl;
#define F first
#define S second
#define mp make_pair

//Smallest node that can be visited from thesubtree of that node
//or a backedge is pointing to.

//Input
// 12 16
// 1 3
// 1 9
// 9 12
// 12 11
// 11 9
// 3 5
// 5 7
// 7 3
// 5 1
// 3 6
// 6 1
// 6 2
// 2 8
// 8 3
// 2 4
// 4 10

//Output
// 1 0
// 2 1
// 3 0
// 4 4
// 5 0
// 6 0
// 7 1
// 8 1
// 9 1
// 10 5
// 11 1
// 12 1

const int N = 100;
vector<int>gr[N];
int dp[N], vis[N], depth[N];
//dp[i] --> min(min(dp[child]),min(backedge))

void dfs(int cur, int p = 0, int dep = 0) {
	vis[cur] = 1;
	dp[cur] = dep;
	depth[cur] = dep;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			dfs(x, cur, dep + 1);
			dp[cur] = min(dp[cur], dp[x]);
		}
		else if (x != p) {
			//Backedge or cycle
			dp[cur] = min(dp[cur], depth[x]);
		}
	}
}

int32_t main() {
	fastio;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	//root is 1
	dfs(1);
	for (int i = 1; i <= n; i++) cout << i << " " << dp[i] << endl;
}
