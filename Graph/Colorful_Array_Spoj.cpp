//                         https://www.spoj.com/problems/CLFLARR/
//<---------------------------------COLORFUL ARRAY------------------------------->
// You have been given an array of n unpainted elements.
// By unpainted, we mean that each element initially has a value of 0.
// You have to process q queries of the form l r c, in which you paint all the elements of the
// array from index l to index r with color c. Assume that, each new color currently being applied
// to an element overrides its previous color. Output the color of each element after all the queries
// have been processed.

// Note: The problem is guaranteed to be solved using C or C++ programming language.

// Input
// The first line of input consists of two integers n and q. Next q lines consists of 3 integers l, r and c denoting the starting index, ending index and the color respectively.

// 1 <= n <= 200000
// 1 <= q <= 200000
// 1 <= l <= r <= n
// 1 <= c <= 1 000 000 000
// Output
// Output the final color of each element starting from index 1 on a new line.

// Example
// Input
// 4 3
// 1 3 2
// 2 4 6
// 2 3 7
// Output:
// 2
// 7
// 7
// 6
// Input
// 10 5
// 3 9 13
// 1 4 9
// 2 10 14
// 2 7 10
// 6 9 44
// Output
// 9
// 10
// 10
// 10
// 10
// 44
// 44
// 44
// 44
// 14

//Soln : Using Disjoint Set union
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

class dsu {
	vector<int>parent;
public:
	void init(int n) {
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}
	int get(int x) {
		return (x == parent[x] ? x : parent[x] = get(parent[x]));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			parent[x] = max(parent[x], parent[y]);
			parent[y] = max(parent[x], parent[y]);
		}
	}
};

int32_t main() {
	int n, q;
	cin >> n >> q;
	int l[q], r[q], c[q];
	for (int i = 0; i < q; i++)
		cin >> l[i] >> r[i] >> c[i];
	dsu G;
	G.init(n + 2);
	int color[n + 2] = {};
	for (int i = q - 1; i >= 0; i--) {
		//rightmost  non-coloured index
		int index = G.get(l[i]);
		while (index <= r[i]) {
			color[index] = c[i];
			G.unite(index, index + 1);
			index = G.get(index);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << color[i] << endl;
}
