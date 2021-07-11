// https://atcoder.jp/contests/dp/tasks/dp_l

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

//dp(i,j) : no. of ways to distribute j candies to first i child
//dp(n,k) : dp(n-1,k) + dp(n-1,k-1) + dp(n-1,k-2) + ..... + dp(n-1,k-min(An,k))
//Base Case : dp(1,j) is 1 if j<=A1, and 0 if j> A1
ll dp[101][100001];
vector<int>v;

ll candies(vector<int>&v, int n, int k) {
  //Base Case
	for (int j = 0; j <= k; j++) dp[1][j] = (j > v[1] ? 0 : 1);
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - ((j - v[i] - 1 >= 0) ? dp[i - 1][j - 1 - v[i]] : 0) + mod) % mod;
		}
	}
	return dp[n][k];
}

int32_t main() {
	fastio;
	int n, k;
	cin >> n >> k;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	cout << candies(v, n, k) << endl;
}
