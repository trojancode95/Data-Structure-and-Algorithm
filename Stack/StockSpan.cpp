//https://practice.geeksforgeeks.org/problems/stock-span-problem/0
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007

//Time Complexity : O(n)
void stockSpan(vector<int>&price, int n, vector<int>&span) {
	stack<int>s;//indices of the day
	s.push(0);
	span.push_back(1);
	for (int i = 1; i < n; i++) {
		int currentPrices = price[i];
		//topmost element that is higher than the current price
		while (!s.empty() && price[s.top()] <= currentPrices)
			s.pop();
		int x = (s.empty() ? (i + 1) : (i - s.top()));
		span.push_back(x);
		//Push this element into this stack
		s.push(i);
	}
}


int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int>price(n);
		for (int i = 0; i < n; i++)
			cin >> price[i];
		vector<int>span;
		stockSpan(price, n, span);
		for (auto x : span)
			cout << x << " ";
		cout << endl;
	}
	return 0;
}
