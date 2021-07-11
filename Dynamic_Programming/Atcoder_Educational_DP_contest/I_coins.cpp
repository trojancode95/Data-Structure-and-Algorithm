// https://atcoder.jp/contests/dp/tasks/dp_i

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

double dp[3000][3000];

//dp[i][x] : probability of getting atleast x heads after tossing i coins
double coin(vector<double>&pr, int i, int x) {
	if (x == 0) return 1;
	if (i == 0) return 0;

	if (dp[i][x] > -1) return dp[i][x];

	return dp[i][x] = pr[i] * coin(pr, i - 1, x - 1) + (1 - pr[i]) * coin(pr, i - 1, x);
}

int32_t main() {
	fastio;
	memset(dp, -1, sizeof dp);
	int n; cin >> n;
	vector<double>pr(n + 1);
	for (int i = 1; i <= n; i++) cin >> pr[i];
	cout << fixed << setprecision(10);
	cout << coin(pr, n, (n + 1) / 2) << endl;
}
