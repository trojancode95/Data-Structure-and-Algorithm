// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
// #define inf INT_MAX
#define inf 1e9+1
#define INF LLONG_MAX
#define minf INT_MIN
#define MINF LLONG_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<<" "; cout<<"\n";
#define printn(v) for(auto x:v) cout<<x<<"\n";
#define F first
#define S second
#define mp make_pair

int dp[101][100001];
vector<int>wt;
vector<int>val;
int n, capacity;

//dp[i][j] : minimum weight W, we have to carry to get the value j
int knapsack_2(int max_profit) {
	for (int j = 0; j <= max_profit; j++) dp[0][j] = inf;
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= max_profit; j++) {
			if (val[i] <= j) dp[i][j] = min(wt[i] + dp[i - 1][j - val[i]], dp[i - 1][j]);
			else dp[i][j] = dp[i - 1][j];
		}
	}
	int ans = 0;
	for (int j = 0; j <= max_profit; j++)
		if (dp[n][j] <= capacity) ans = j;
	return ans;
}

int32_t main() {
	fastio;
	cin >> n >> capacity;
	wt.resize(n + 1, 0);
	val.resize(n + 1, 0);
	int max_profit{};
	for (int i = 1; i <= n; i++) {
		cin >> wt[i] >> val[i];
		max_profit += val[i];
	}
	cout << knapsack_2(max_profit) << endl;
}
