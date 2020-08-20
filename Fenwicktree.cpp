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

struct fenwick_tree {
	vector<int>f;
	int n;
	void init(int n) {
		this->n = n + 1;
		f.resize(n + 1, 0);
	}
	//Returns sums of prefix from 1...x
	int sum(int x) {
		x++;//Due to one based indexing
		int ans = 0;
		while (x > 0) {
			ans += f[x];
			x = x - (x & -x);
		}
		return ans;
	}
	//Add value to index idx
	void add(int idx, int val) {
		idx++;//Due to one based indexing
		while (idx < n) {
			f[idx] += val;
			idx = idx + (idx & -idx);
		}
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

int32_t main() {
	fastio;
	int n;
	cin >> n;
	fenwick_tree tree;
	tree.init(n);
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tree.add(i, a[i]);
	}
	cout << tree.sum(0) << endl;
	cout << tree.sum(2, 4) << endl;
	cout << tree.sum(4) << endl;
	cout << tree.sum(1, 3) << endl;
}
