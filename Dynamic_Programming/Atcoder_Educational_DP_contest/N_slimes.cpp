// https://atcoder.jp/contests/dp/tasks/dp_n

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

//dp(i,j) : minimum cost to combines slimes from range i to j to make single slimes
//dp(i,i) ; 0
//dp(i,j) : sum(i,j) + dp(i,k) + dp(k+1,j) where k belongs from i to j-1
ll dp[401][401];
ll sum[401][401];
vector<int>v;

ll slime(int i, int j) {
	if (i == j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	ll min_cost = INF;
	for (int k = i; k + 1 <= j; k++)
		min_cost = min(min_cost, sum[i][j] + slime(i, k) + slime(k + 1, j));
	return dp[i][j] = min_cost;
}

void pre_processing(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			sum[i][j] = v[j] + (j == i ? 0 : sum[i][j - 1]);
}

int32_t main() {
	fastio;
	memset(dp, -1, sizeof dp);
	int n; cin >> n;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> v[i];
	pre_processing(n);
	cout << slime(1, n) << endl;
}
