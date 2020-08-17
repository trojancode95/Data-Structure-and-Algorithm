#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007

ll max_hist_area(ll hist[], ll n) {
	stack<ll>s;
	ll max_area = 0;
	ll i = 0;
	while (i < n) {
		if (s.empty() || hist[s.top()] <= hist[i])
			s.push(i++);
		else {
			ll tp = s.top();
			s.pop();
			ll current_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
			max_area = max(max_area, current_area);
		}
	}
	while (!s.empty()) {
		ll tp = s.top();
		s.pop();
		ll current_area = hist[tp] * (s.empty() ? i : i - s.top() - 1);
		max_area = max(current_area, max_area);
	}
	return max_area;
}


int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll hist[n];
		for (int i = 0; i < n; i++)
			cin >> hist[i];
		cout << max_hist_area(hist, n) << endl;
	}

	return 0;
}
