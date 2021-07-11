//Top Down Dp : Recursion and Memoization
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007



int n = 4;
//Adjacency matrix which defines our graph
//dist[i][j] : distance between city i and city j.
int dist[10][10] = {
	{0, 20, 42, 25},
	{20, 0, 30, 34},
	{42, 30, 0, 10},
	{25, 34, 10, 0}
};
//If all cities has been visited
int visited_all = (1 << n) - 1; //(1111)

int dp[1 << 4][4];
//mask denotes the set of city which has been visited so far
int tsp(int mask, int pos) {
	//Base Case
	if (mask == visited_all)
		return dist[pos][0];

	//Lookup Case
	if (dp[mask][pos] != -1)
		return dp[mask][pos];

	int ans = INT_MAX;
	//Try to go to unvisited cities
	for (int city = 0; city < n; city++) {
		//It that set bit is off ,it means that city is not visited.
		if ((mask & (1 << city)) == 0) {
			int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
			ans = min(ans, newAns);
		}
	}
	return dp[mask][pos] = ans;
}

int main()
{
	fast;
	for (int i = 0; i < (1 << n); i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
	cout << "Minimum Weight Hamiltonian path costs " << tsp(1, 0) << endl;
	return 0;
}
