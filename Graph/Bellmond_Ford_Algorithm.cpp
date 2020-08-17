// //Bellman Ford Algorithm
// ----> Single source shortest path Algorithm.
// ----> Also handle negative weight edges.
// ----> Negative Weight cycle : If there is a path from source to destination
//       where i encounters a cycle whose total weight of all the edges is Negative
//       ,then the minimum distance from source to destination will be minus infinity.
// ----> Why not Dijsktra ? It works only for non negative edges.
// ----> Bellman Ford Algorithm also works for positive edges but we use Dijsktra
//       because it has a time complexity of O(VlogE).
// ----> Bellman Ford Algorithm works in time complexity of O(V * E).
// ----> Why directed , not undirected ? If in a undirected graph , there is a
//       negative weight edges, then we cannot apply Bellman Ford Algorithm
//       because it will make a negative weight cycles.
// ----> It works like a dynamic programming way.
// ----> Worst Path Length from source to destination (1-->2-->3-->4-->5) can be (N(nodes)-1) edges.
//       It means that (n-1) iteration or we have to apply Bellman Ford Algorithm
//       (n-1) times to find shortest path from source to destination.
// ----> We will not consider cycle in positive weight cycles.
// ----> If there is a negative weight cycle , then  Relaxation of edges will be
//       done infinity times.
//
// <----------------------------Methods----------------------------------------->
// 1---> distance of source will be zero and distance of other vertex will be INT_MAX.
// 2---> Relax all edges (n-1) times.
// 3---> If I can perform further Relaxation on any edge, then that edge is in negative
//       weight cycles because atmost (n-1) Relaxation is required for Bellman Ford
//       Algorithm.
//
// Example 1.
// Input :
// 3 3
// 2 1 -4
// 1 3 5
// 3 2 -7
// Output :
// There is a negative weight cycle in our Graph
//
// Example 2.
// Input :
// 3 3
// 1 2 4
// 1 3 5
// 3 2 -7
// Output :
// Distance from source to 1 : 0
// Distance from source to 2 : -2
// Distance from source to 3 : 5



#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007

//Code for Bellman Ford Algorithm

vector<int>bellman_ford(int n, int src, vector<vector<int>>edges) {
  	//Minimum distance from source to i.
  	//dist(src,i).
  	vector<int> dist(n + 1, INT_MAX);
  	dist[src] = 0;

  	//Relax all the edges (n-1) times.
  	for (int i = 0; i < n - 1; i++) {
  		for (auto x : edges) {
  			int from = x[0], to = x[1], weight = x[2];
  			if (dist[from] != INT_MAX && dist[to] > dist[from] + weight)
  				//Relaxed the edges (n-1) times.
  				dist[to] = dist[from] + weight;
  		}
  	}
  	//Let's check for negative weight cycle.
  	for (auto x : edges) {
  		int from = x[0], to = x[1], weight = x[2];
  		if (dist[from] != INT_MAX && dist[to] > dist[from] + weight) {
  			cout << "There is a negative weight cycle in our Graph" << endl;
  			exit(0);//It will successfully terminate the program.
  		}
  	}
  	return dist;
}

int main() {
  	fast;
  	int n, m;
  	cin >> n >> m;
  	vector<vector<int>>edges;
  	for (int i = 0; i < m; i++) {
  		int from, to, weight;
  		cin >> from >> to >> weight;
  		edges.push_back({from, to, weight});
  	}
  	int src = 1;
  	vector<int>distance = bellman_ford(n, src, edges);
  	for (int i = 1; i <= n; i++)
  		cout << "Distance from source to " << i << " : " << distance[i] << endl;
  	cout << endl;

  	return 0;
}
