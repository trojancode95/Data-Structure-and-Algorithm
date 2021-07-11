// https://atcoder.jp/contests/dp/tasks/dp_a

//dp[i] : represents the minimum cost to reach stone number i from stone number 0.
//Goal : to find dp[n]
//dp[n] = min(|h(n)-h(n-1)| + dp[n-1] , |h(n)-h(n-2)| + dp[n-2])

#include <bits/stdc++.h>
using namespace std;

//Bottom Up Approach
int frog1(vector<int>h, int n) {
	vector<int>dp(n + 1);
	dp[1] = 0;
	dp[2] = abs(h[2] - h[1]);
	for (int i = 3; i <= n; i++) {
		int option1 = abs(h[i] - h[i - 1]) + dp[i - 1];
		int option2 = abs(h[i] - h[i - 2]) + dp[i - 2];
		dp[i] = min(option1, option2);
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int>h(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	cout << frog1(h, n) << endl;


	return 0;
}
