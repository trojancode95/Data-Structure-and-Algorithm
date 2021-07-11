// https://atcoder.jp/contests/dp/tasks/dp_h

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

int dp[1000][1000];

int grid_dp(int h, int w) {
	for (int i = 0; i < w; i++) {
		if (dp[0][i] != 0) continue;
		for (int j = i + 1; j < w; j++) dp[0][j] = 0;
		break;
	}
	for (int i = 0; i < h; i++) {
		if (dp[i][0] != 0) continue;
		for (int j = i + 1; j < h; j++) dp[j][0] = 0;
		break;
	}
	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (dp[i][j] == 0) continue;
			dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
		}
	}
	return dp[h - 1][w - 1] ;
}

int32_t main() {
	fastio;
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char ch; cin >> ch;
			if (ch == '.') dp[i][j] = 1;
			else dp[i][j] = 0;
		}
	}
	cout << grid_dp(h, w) << endl;
}
