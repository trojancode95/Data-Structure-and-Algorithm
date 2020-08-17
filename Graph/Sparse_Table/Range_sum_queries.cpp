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

const int N = 100005, M = 22;

int32_t main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int log[n + 1];
	log[1] = 0;
	for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1;
	int k = log2(n);
	int st[n][k + 1];
	for (int i = 0; i < n; i++) st[i][0] = a[i];
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
	}
	int q;
	cin >> q;
	while (q--) {
		int L, R;
		cin >> L >> R;
		int sum = 0;
		for (int j = k; j >= 0; j--) {
			if ((1 << j) <= R - L + 1) {
				sum += st[L][j];
				L += 1 << j;
			}
		}
		cout << sum << endl;
	}
}
