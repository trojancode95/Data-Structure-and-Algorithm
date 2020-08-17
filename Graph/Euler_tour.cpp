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
#define S second
#define mp make_pair
const int N = 100005, M = 22;

vector<int>gr[N];
int tin[N], tout[N], timer;

void euler_tour_1(int cur, int par) {
	cout << cur << " ";
	for (auto x : gr[cur]) {
		if (x != par) {
			euler_tour_1(x, cur);
			cout << cur << " ";
		}
	}
}

void euler_tour_2(int cur, int par) {
	cout << cur << " ";
	//tin[cur]=timer++;
	for (auto x : gr[cur]) {
		if (x != par)
			euler_tour_2(x, cur);
	}
	//tout[cur]=timer++;
	cout << cur << " ";
}

void euler_tour_3(int cur, int par) {
	//cout << cur << " ";
	//Enter a node
	tin[cur] = ++timer;
	for (auto x : gr[cur]) {
		if (x != par)
			euler_tour_3(x, cur);
	}
	//Leave a node
	tout[cur] = timer;
}

//Whether x is ancestor of y or not
bool is_ancestor(int x, int y) {
	return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int32_t main() {
	FASTIO;
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}
	timer = 0;
	// euler_tour_1(1, 0);
	// cout << endl;
	// euler_tour_2(1, 0);
	// cout << endl;
	euler_tour_3(1, 0);
	for (int i = 1; i <= n; i++)
		cout << i << " " << tin[i] << " " << tout[i] << endl;
	if (is_ancestor(2, 6))
		cout << "2 is a ancestor of 6";
	else
		cout << "2 is not a ancestor of 6";
	cout << endl;
}
