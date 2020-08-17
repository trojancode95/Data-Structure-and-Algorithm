// https://www.spoj.com/problems/HOLI/                    HOLI - Holiday Accommodation | Spoj
// <---------------------------------------------------------------------------------------------------------------------------------------->
// Nowadays, people have many ways to save money on accommodation when they are on vacation. One of these ways is exchanging houses with other people.
//
// Here is a group of N people who want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone's house temporary. Now they want to make a plan that choose a destination for each person. There are two rules should be satisfied:
//
// All the people should go to one of the other people's city.
// Two of them never go to the same city, because they are not willing to share a house.
// They want to maximize the sum of all people's travel distance. The travel distance of a person is the distance between the city he lives in and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when traveling.
//
// Given the highways' information, it is your job to find the best plan, that maximum the total travel distance of all people.
//
// Input
// The first line of input contains one integer T (1 ≤ T ≤ 10), indicating the number of test cases.
//
// Each test case contains several lines. The first line contains an integer N (2 ≤ N ≤ 105), representing the number of cities. Then the following N-1 lines each contains three integers X, Y, Z (1 ≤ X, Y ≤ N, 1 ≤ Z ≤ 106), means that there is a highway between city X and city Y, and length of that highway.
//
// You can assume all the cities are connected and the highways are bi-directional.
//
// Output
// For each test case in the input, print one line: "Case #X: Y", where X is the test case number (starting with 1) and Y represents the largest total travel distance of all people.
//
// Example
// Input:
// 2
// 4
// 1 2 3
// 2 3 2
// 4 3 2
// 6
// 1 2 3
// 2 3 4
// 2 4 1
// 4 5 8
// 5 6 5
//
// Output:
// Case #1: 18
// Case #2: 62
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007


class Graph {
			int V;
			list<pair<int, int>>*l;
		public:
			Graph(int v) {
				V = v;
				l = new list<pair<int, int>>[V];
			}
			void addEdge(int u, int v, int cost) {
				l[u].push_back({v, cost});
				l[v].push_back({u, cost});
			}

			int dfsHelper(int node, bool *visited, int *count, int &ans) {
				//mark the node as visited
				visited[node] = 1;
				count[node] = 1;
				for (auto nbr_cost_pair : l[node]) {
					int nbr = nbr_cost_pair.first;
					int cost = nbr_cost_pair.second;
					if (!visited[nbr]) {
						count[node] += dfsHelper(nbr, visited, count, ans);
						int nx = count[nbr];
						int ny = V - nx;
						ans += 2 * min(nx, ny) * cost;
					}
				}
				//Just before leaving the node parent
				return count[node];
		}

			int dfs() {
			bool *visited = new bool[V] {};
			int *count = new int [V] {};
			int ans{};
			dfsHelper(0, visited, count, ans);

			return ans;
	 	}
};

int32_t main() {
			int t;
			cin >> t;
			for(int x=1;x<=t;x++) {
				int V;
				cin >> V;
				Graph g(V);
				for (int i = 0; i < V-1; i++) {
					int u, v, cost;
					cin >> u >> v >> cost;
					u--;
					v--;
					g.addEdge(u, v, cost);
				}
				cout <<"Case #"<<x<<": "<<g.dfs() << endl;
			}
			return 0;
}
