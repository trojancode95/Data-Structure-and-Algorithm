#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007


void nextGreaterElement(vector<ll>&a, ll n, vector<ll>&ans) {
    	stack<ll>s;
    	ans.push_back(-1);
    	s.push(a[n - 1]);
    	for (ll i = n - 2; i >= 0; i--) {
    		while (!s.empty() && s.top() <= a[i])
    			s.pop();
    		ll x = (s.empty() ? -1 : s.top());
    		ans.push_back(x);
    		s.push(a[i]);
    	}
    	reverse(ans.begin(), ans.end());
}

int32_t main() {
    	fast;
    	int t;
    	cin >> t;
    	while (t--) {
    		ll n;
    		cin >> n;
    		vector<ll>a(n);
    		for (ll i = 0; i < n; i++)
    			cin >> a[i];
    		vector<ll>ans;
    		nextGreaterElement(a, n, ans);
    		for (auto x : ans)
    			cout << x << " ";
    		cout << endl;
    	}
    	return 0;
}
