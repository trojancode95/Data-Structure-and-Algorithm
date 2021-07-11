//https://atcoder.jp/contests/dp/tasks/dp_o

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
#define setbit __builtin_popcount
#define setbitll __builtin_popcount


const int N = 22;
int compat[N][N];
int dp[N][1 << N];

ll solve(int i, int n, int womensubset) {
    if (i == n + 1) {
        if (womensubset == 0) return 1;
        else return 0;
    }

    if (dp[i][womensubset] != -1) return dp[i][womensubset];

    ll ans = 0;
    for (int women = 0; women < n; women++) {
        bool available = (1 << women) & womensubset;
        if (available && compat[i][women + 1]) {
            ans = (ans + solve(i + 1, n, (womensubset ^ (1 << women)))) % mod;
        }
    }
    return dp[i][womensubset] = ans;
}

int32_t main() {
    fastio;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> compat[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << solve(1, n, ((1 << n) - 1)) << endl;

}