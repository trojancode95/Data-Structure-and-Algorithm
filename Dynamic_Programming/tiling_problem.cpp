// Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.
//
// Input Format
// First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
// The first line of each test case contains two integers N and M.
//
// Constraints
// 1 <= T<= 1000
// 1 <= N,M <= 100000
//
// Output Format
// Print answer for every test case in a new line modulo 10^9+7.
//
// Sample Input
// 2
// 2 3
// 4 4
// Sample Output
// 1
// 2

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


int tiling(int n, int m) {
	if (n < m) return 1;
	if (n == m) return 2;
	int dp[n + 1];
	dp[0] = 0;
	for (int i = 1; i < m; i++) dp[i] = 1;
	dp[m] = 2;
	for (int i = m + 1; i <= n; i++) dp[i] = (dp[i - 1] % mod + dp[i - m] % mod) % mod;
	return dp[n];
}

int32_t main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << tiling(n, m) << endl;
	}
	return 0;
}
