// https://atcoder.jp/contests/dp/tasks/dp_f

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

string s, t;
int dp[3000][3000];

int len_lcs(int i, int j, int n, int m) {
	if (i >= n || j >= m) return 0;
	if (dp[i][j] != -1) return dp[i][j];

	if (s[i] == t[j]) return dp[i][j] = 1 + len_lcs(i + 1, j + 1, n, m);
	else return dp[i][j] = max(len_lcs(i + 1, j, n, m), len_lcs(i, j + 1, n, m));
}

string get_lcs(int len) {
	int i = 0, j = 0;
	string lcs;
	while (len > 0) {
		if (s[i] == t[j]) {
			lcs.pb(s[i]);
			i++;
			j++;
			len--;
		}
		else if (dp[i + 1][j] > dp[i][j + 1]) i++;
		else j++;
	}
	return lcs;
}

int32_t main() {
	fastio;
	cin >> s >> t;
	int n = s.length();
	int m = t.length();
	memset(dp, -1, sizeof dp);
	int len = len_lcs(0, 0, n, m);
	cout << get_lcs(len) << endl;
}
