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

//Smallest node in a subtree of that node
const int N = 100;
vector<int>gr[N];
int dp[N];//dp[i] is min(i and min(all the child of i))

void dfs(int cur, int p = 0) {
	dp[cur] = cur;
	for (auto x : gr[cur]) {
		if (x != p) {
			dfs(x, cur);
			dp[cur] = min(dp[cur], dp[x]);
		}
	}
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
	//root is 1
	dfs(1);
	for (int i = 1; i <= n; i++) cout << i << " " << dp[i] << endl;
}
