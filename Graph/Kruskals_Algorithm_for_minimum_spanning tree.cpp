//Kruskal's Algorithm for finding the minimum spanning tree.
//A minimum spanning tree (MST) or minimum weight spanning tree is a subset of
//the edges of a connected, edge-weighted undirected graph that connects all
//the vertices together, without any cycles and with the minimum possible total
//edge weight.
//Pre-requisite :- Disjoint set Union

//Step 1.Sort all the edges according to the increasing order of weight.
//Step 2.If I add that esges in the graph and resulting graph has no cycle.Then that edge is a worthy edge.

// Input
// 9 15
// 1 2 10
// 2 3 9
// 1 3 12
// 3 5 3
// 5 4 7
// 2 4 8
// 3 6 1
// 4 6 10
// 5 6 3
// 7 4 8
// 7 8 9
// 7 9 2
// 8 6 6
// 9 7 2
// 9 8 11

// Output : 43

#include<bits/stdc++.h>
using namespace std;

class disjointSetUnion {
public:
    	vector<int>parent;
    	void Initialize(int n) {
    		parent.clear();
    		parent.resize(n);
    		iota(parent.begin(), parent.end(), 0);
    	}
    	int get_SuperParent(int x) {
    		return (x == parent[x] ? x : (parent[x] = get_SuperParent(parent[x])));
    	}
    	void unite(int x, int y) {
    		x = get_SuperParent(x);
    		y = get_SuperParent(y);
    		if (x != y)
    			parent[x] = y;
    	}
};


void KrushkalsAlgorithm() {
      	bool cycle = false;
      	int n, m;
      	cin >> n >> m; // n number of nodes and m pairs
      	vector<vector<int>>edges(m);
      	for (int i = 0; i < m; i++) {
      		int x, y, w; //Edges x-->y having weight w
      		cin >> x >> y >> w;//1 based Indexing.
      		edges[i] = {w, x, y};
      	}
      	sort(edges.begin(), edges.end());
      	disjointSetUnion G;
      	G.Initialize(n + 1); // Nodes from 1--->n.
      	int total_weight_of_the_minimum_spanning_tree = 0;
      	for (int i = 0; i < m; i++) {
      		int x = edges[i][1];
      		int y = edges[i][2];
      		int w = edges[i][0];
      		//cout << w << " " << x << " " << y << endl;
      		if (G.get_SuperParent(x) != G.get_SuperParent(y)) {
      			//Can take this edge because it is not creating a cycle
      			G.unite(x, y);
      			cout << w << " " << x << " " << y << endl;
      			//If you want to make a unidirected graph of minimum spanning tree
      			//ad[x].push_back(y); ad[y],push_back(x);
      			//Include all the edge which doesnot result in a cycle.
      			total_weight_of_the_minimum_spanning_tree += w;
      		}
      	}
      	cout << "Total weight of the minimum spanning tree is " << total_weight_of_the_minimum_spanning_tree << endl;
}

int main() {
      	ios_base::sync_with_stdio(false);
      	cin.tie(NULL);
      	cout.tie(NULL);

      	KrushkalsAlgorithm();
}
































// #include<bits/stdc++.h>
// using namespace std;
// class disjointSetUnion {
// public:
// 	int parent[100001];
// 	void Initialize(int n) {
//
// 		for (int i = 0; i < n; i++)
// 			parent[i] = i;
// 	}
//
// 	int get_SuperParent(int x) {
// 		return (x == parent[x] ? x : (parent[x] = get_SuperParent(parent[x])));
// 	}
//
// 	void unite(int x, int y) {
// 		x = get_SuperParent(x);
// 		y = get_SuperParent(y);
// 		if (x != y)
// 			parent[x] = y;
// 	}
// };
//
// long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) {
// 	pair<long long int, pair<int, int> > v[2 * m];
// 	int t = 0;
//
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j < adj[i].size(); j++) {
// 			v[t++] = make_pair(adj[i][j].second, make_pair(i, adj[i][j].first));
// 		}
// 	}
//
// 	sort(v, v + t);
// 	disjointSetUnion G;
// 	G.Initialize(n + 1);
// 	ll ans = 0;
// 	for (int i = 0; i < 2 * m; i++) {
// 		int x = v[i].second.first;
// 		int y = v[i].second.second;
// 		long long w = v[i].first;
// 		if (G.get_SuperParent(x) != G.get_SuperParent(y)) {
// 			G.unite(x, y);
// 			ans += w;
// 		}
// 	}
// 	return ans;
// }
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
// 	int t;
// 	cin >> t;
// 	vector<pair<int, long long int>>adj[100009];
// 	while (t--) {
// 		int n, m;
// 		cin >> n >> m;
// 		int u, v;
// 		ll w;
// 		for (int i = 0; i < m; i++) {
// 			cin >> u >> v >> w;
// 			adj[u].push_back(make_pair(v, w));
// 			adj[v].push_back(make_pair(u, w));
// 		}
// 		cout << kruskalDSU(adj, n, m) << endl;
// 		for (int i = 0; i < m; i++)
// 			adj[i].clear();
// 	}
// 	return 0;
// }
