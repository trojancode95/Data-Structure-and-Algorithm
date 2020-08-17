//                        Kosaraju's Algorithm for Strongly connected components
// <--------------------------------------------------------------------------------------------------------------------------------->
// Strongly Connectd Graph : This term is strictly used for directed Graph.

// Input :
// 6 7
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5
// 5 6
// 6 4
//
// Output :
// 1 ---> 2
// 2 ---> 2
// 3 ---> 2
// 4 ---> 3
// 5 ---> 3
// 6 ---> 3


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007


//Kosaraju's Algorithm : O(n) time complexity
const int N = 100005, M = 22;
vector<int>Graph[N], reverseGraph[N];
vector<int>order;//If there is a path from x to y, then y should come before x in the order vector
int visited[N], component[N];

void dfs(int current) {
     visited[current] = 1;
     for (auto x : Graph[current]) {
       if (!visited[x]) dfs(x);
     }
     order.push_back(current);
}

void dfs_reverse(int current, int color) {
     visited[current] = 1;
     component[current] = color;
     for (auto x : reverseGraph[current]) {
       if (!visited[x])
         dfs_reverse(x, color);
     }
}

void solve() {
     int n, m;
     cin >> n >> m;
     for (int i = 0; i < m; i++) {
       int x, y;
       cin >> x >> y;
       Graph[x].push_back(y);
       reverseGraph[y].push_back(x);
     }
     // memset(visited, 0, sizeof(visited));
     for (int i = 1; i <= n; i++) {
       if (!visited[i]) dfs(i);
 }
 memset(visited, 0, sizeof(visited));
     int color = 1;
     for (int i = n; i >= 1; i--) {
       if (!visited[order[i]]) {
         dfs_reverse(order[i], color);
         color++;
       }
 }
      for (int i = 1; i <= n; i++)
        cout << i << " ---> " << component[i] << endl;
}

int32_t main() {
     fast;
     solve();
     return 0;
}
