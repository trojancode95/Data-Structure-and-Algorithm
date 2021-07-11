// https://atcoder.jp/contests/dp/tasks/dp_j

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

double dp[301][301][301];

//dp(x,y,z) = 1 + P(0)*dp(x,y,z) + P(x)*dp(x-1,y,z) + P(y)*dp(x+1,y-1,z) + P(z)*dp(x,y+1,z-1)
double sushi(int n, int x, int y, int z) {
	if (x < 0 || y < 0 || z < 0) return 0;

	if (x == 0 && y == 0 && z == 0) return 0;

	if (dp[x][y][z] > -0.9 ) return dp[x][y][z];

	return dp[x][y][z] = (n + x * sushi(n, x - 1, y, z) + y * sushi(n, x + 1, y - 1, z) + z * sushi(n, x, y + 1, z - 1)) / (x + y + z);
}

int32_t main() {
	fastio;
	memset(dp, -1, sizeof dp);
	int n; cin >> n;
	int one{}, two{}, three{}; //No. of dishes having 1 sushies, two sushies and three sushies .NO. of zero sushies : N-(one + two + three)
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == 1) one++;
		if (x == 2) two++;
		if (x == 3) three++;
	}
	cout << fixed << setprecision(10);
	cout << sushi(n, one, two, three) << endl;
}
