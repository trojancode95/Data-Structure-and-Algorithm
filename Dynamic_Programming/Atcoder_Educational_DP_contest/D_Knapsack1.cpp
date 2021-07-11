//Knapsack 1
// https://atcoder.jp/contests/dp/tasks/dp_d
//dp(n,w):subset of the items from 1...n and capacity is w.
// Top Down Approach
// dp(n,w) : (1....n-1) having capacity of the Knapsack w if we do not include the nth items.
//         : (1....n-1) + Vn having capacity of the Knapsack W-W(n)
// dp(n,w) : max(dp(n-1,w) , V(n) + dp(n-1,W-W(n)))
//
// Base Case : dp[0,x] = 0;

//Bottom Up Approach
// dp(i,w) : subset of the items from 1....i such that sum of the weight is exactly W.
// ith item : We can either choose it or leave it.
// dp(i,w) : max(V(i) + dp(i-1,W-W(i)) , dp(i-1,w))
// dp[n][x] : 0<=x<=w
// dp(1,x) = 0 if x!=W(i)
// dp(1,x) = 0 if x=W(i)

// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
#define inf INT_MAX
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

ll dp[101][100001];
vector<int>wt, val;

//Top Down DP
ll knapsack_TD(int n, int w) {
	if (n == 0 || w == 0) return 0;

	if (dp[n][w] != -1) return dp[n][w];

	if (wt[n] > w) return dp[n][w] = knapsack_TD(n - 1, w);
	else return  dp[n][w] = max(val[n] + knapsack_TD(n - 1, w - wt[n]), knapsack_TD(n - 1, w));
}

//Bottom up DP
ll knapsack_BU(int n, int w) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (wt[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(val[i] + dp[i - 1][j - wt[i]], dp[i - 1][j]);
		}
	}
	return dp[n][w];
}

int32_t main() {
	fastio;
	int n, w;
	cin >> n >> w;
	// memset(dp, -1, sizeof dp);
	wt.resize(n + 1, 0);
	val.resize(n + 1, 0);
	for (int i = 1; i <
		= n; i++) cin >> wt[i] >> val[i];
	cout << knapsack_BU(n, w) << endl;
}
