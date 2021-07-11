#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
#define inf INT_MAX
#define minf INT_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<<" "; cout<<endl;
#define printn(v) for(auto x:v) cout<<x<<endl;
#define F first
#define S secon
#define mp make_pair

const int N = 100005, M = 23;
vector<int>gr[N];
int disc[N], low[N], timer;
set<int>art_point;
vector<pair<int, int>>bridge;

void dfs(int cur, int par = 0) {
	int no_of_child = 0;
	disc[cur] = low[cur] = timer++;
	for (auto child : gr[cur]) {
		if (!disc[child]) {
			dfs(child, cur);
			no_of_child++;
			low[cur] = min(low[cur], low[child]);
			//Articulation point
			if (par != 0 && low[child] >= disc[cur])
				art_point.insert(cur);
			//Bridge
			if (low[child] > disc[cur])
				bridge.pb({cur, child});
		}
		else if (child != par) {
			//Backedge and cycle found
			low[cur] = min(low[cur], disc [child]);
		}
	}
	//Separate case for root to be Articulation Point
	if (par == 0 && no_of_child >= 2)
		art_point.insert(cur);
}

int32_t main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	timer = 1;
	dfs(1);
	for (auto x : art_point)
		cout << x << " ";
	cout << endl;
	for (auto x : bridge)
		cout << x.first << " --- " << x.second << endl;
}
