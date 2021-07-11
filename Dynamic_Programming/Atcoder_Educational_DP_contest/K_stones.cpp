// https://atcoder.jp/contests/dp/tasks/dp_k

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

string k_stones(vector<int>&v, int k) {
	int dp[k + 1] = {};
	for (int i = 1; i <= k; i++) {
		for (int move : v) {
			if (i - move >= 0 && dp[i - move] == 0) dp[i] = 1;
		}
	}
	return dp[k] == 1 ? "First" : "Second";
}

int32_t main() {
	fastio;
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << k_stones(v, k) << endl;
}
