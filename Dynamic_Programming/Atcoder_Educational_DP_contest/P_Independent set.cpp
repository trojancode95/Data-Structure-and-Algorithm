//https://atcoder.jp/contests/dp/tasks/dp_p

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

const int N = 1e5 + 10;
int dp[N][2];
vector<int>tree[N];
int u, v;

ll solve(int u, int constraint, int parent) {
    if (dp[u][constraint] != -1) return dp[u][constraint];

    ll ans = 0;
    ll w = 1;
    for (int child : tree[u]) {
        if (child != parent) w = (w * solve(child, 0, u)) % mod;
    }
    ans = (ans + w);

    if (!constraint) {
        w = 1;
        for (int child : tree[u]) {
            if (child != parent) w = (w * solve(child, 1, u)) % mod;
        }
        ans = (ans + w) % mod;
    }
    return dp[u][constraint] = ans;
}

int32_t main() {
    fastio;
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    cout << solve(1, 0, -1) << endl;
}