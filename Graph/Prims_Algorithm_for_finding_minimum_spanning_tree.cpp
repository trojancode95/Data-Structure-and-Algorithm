//Prim's Algorithm for finding the minimum spanning tree.
//MST Vertex : Vertex is included in my MST.
//MST Edge or Active Edge : It points from the MST vertex to the non MST Vertex.
//MST Edge : Edge that is included in the MST.
//It is an greedy Algorithm.

// 1. Choose a Source Vertex(Any Vertex in Graph)
// 2. Out of all the active edges, choose the one with smallest weight.
// 3. Update the adjacency list.
//
// https://www.spoj.com/problems/MST/
// Find the minimum spanning tree of the graph.
//
// Input
// On the first line there will be two integers N - the number of nodes and M - the number of edges. (1 <= N <= 10000), (1 <= M <= 100000)
// M lines follow with three integers i j k on each line representing an edge between node i and j with weight k. The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be <= 1000000.
//
// Output
// Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.
//
// Example
// Input:
// 4 5
// 1 2 10
// 2 3 15
// 1 3 5
// 4 2 2
// 4 3 40
//
// Output:
// 17

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"


int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);

    	int n, m;
    	cin >> n >> m;
    	vector<pair<int, int>>graph[n + 1]; //1 based indexing
    	//Visited means it is not an active edge and we will not consider it in MST.
    	int visited[n + 1] = {0};
    	for (int i = 0; i < m; i++) {
    		int x, y, w;
    		cin >> x >> y >> w;
    		graph[x].push_back({y, w});
    		graph[y].push_back({x, w});
    	}
    	ll mst = 0;
    	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>Q;
    	Q.push({0, 1}); //(weight,vertex/node)
    	while (!Q.empty()) {
    		pair<int, int>best = Q.top();
    		Q.pop();

    		int weight = best.first;
    		int to = best.second;

    		if (visited[to]) continue; //If it not an active edge ,then we wont be considering it in our MST.
    		mst += weight;
    		visited[to] = 1;

    		//"to" vertex is visited , so we will push all the active edge which is going through this "to" vertex.
    		for (auto x : graph[to]) {
    			//x.first is not visited
    			if (visited[x.first] == 0)
    				Q.push({x.second, x.first});
    		}
    	}
    	cout << mst << endl;


    	return 0;
}
