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

ll dp[3001][3001];
vector<int>v;

ll L_deque(int i, int j, int turn) {
	if (i > j) return 0;

	if (dp[i][j] != -1) return dp[i][j];

	if (turn == 1) return dp[i][j] = max(v[i] + L_deque(i + 1, j, 0), v[j] + L_deque(i, j - 1, 0));
	else return dp[i][j] = min(L_deque(i + 1, j, 1), L_deque(i, j - 1, 1));
}

int32_t main() {
	fastio;
	memset(dp, -1, sizeof dp);
	int n; cin >> n;
	v.resize(n + 1);
	ll sum{};
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	ll x = L_deque(1, n, 1);
	ll y = sum - x;
	cout << x - y << endl;
}
