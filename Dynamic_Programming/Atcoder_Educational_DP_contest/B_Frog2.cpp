https://atcoder.jp/contests/dp/tasks/dp_b

dp[i] : Minimum Cost to reach stone i.
Goal : to find dp[n].
dp[i] : min(|h(i)-h(j)| + dp[j]) over all valid values of j. j can be from i, i-1, i-2.....i-k.
Base Case : dp[1] is zero as frog didnt need to jump to reach 1.

#include <bits/stdc++.h>
using namespace std;

//Bottom Up Approach
int frog2(vector<int>h, int n, int k) {
	vector<int>dp(n + 1);
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = INT_MAX;
    // Condition (i-j<=k) ----> We can only jump from stone which is atmost k distance from the stone.
		for (int j = i - 1; j >= 1 && (i - j) <= k; j--)
			dp[i] = min(dp[i], abs(h[i] - h[j]) + dp[j]);
	}
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int>h(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	cout << frog2(h, n, k) << endl;


	return 0;
}
