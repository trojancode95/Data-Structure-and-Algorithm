#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
#define inf INT_MAX
#define minf INT_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<<" "; cout<<"\n";
#define printn(v) for(auto x:v) cout<<x<<"\n";
#define F first
#define S second
#define mp make_pair

//Splitwise Algorithm in Cash transaction
//Minimum number of transaction needed for settlement among friends
// int32_t main() {
// 	fastio;
// 	int no_of_transaction, no_of_friend;
// 	cin >> no_of_transaction >> no_of_friend;
// 	int x, y, amount;
// 	int net[100000] = {};
// 	while (no_of_transaction--) {
// 		cin >> x >> y >> amount;
// 		net[x] -= amount;
// 		net[y] += amount;
// 	}
// 	multiset<int>m;
// 	for (int i = 0; i < no_of_friend; i++)
// 		if (net[i] != 0) m.insert(net[i]);
// 	int cnt = 0;//Minimum number of transaction needed for settlement
// 	//Pop out two persosn from left and right and settle them
// 	while (!m.empty()) {
// 		auto low = m.begin();
// 		auto high = prev(m.end());
// 		int debit = *low;
// 		int credit = *high;
// 		m.erase(low);
// 		m.erase(high);
// 		//Settlement
// 		int settlement_amount = min(-debit, credit);
// 		cnt++;
// 		//Settlement amount from donor to acceptor
// 		debit += settlement_amount;
// 		credit -= settlement_amount;
// 		if (debit != 0) m.insert(debit);
// 		if (credit != 0) m.insert(credit);
// 	}
// 	cout << cnt << endl;
// }

class person_compare {
public:
	bool operator()(pair<string, int>p1, pair<string, int>p2) {
		return p1.second < p2.second;
	}
};

//Splitwise Algorithm in Cash transaction
//Distribution of money among friends for settlement
int32_t main() {
	fastio;
	int no_of_transaction, no_of_friend;
	cin >> no_of_transaction >> no_of_friend;
	map<string, int>net;
	string x, y; int amount;
	while (no_of_transaction--) {
		cin >> x >> y >> amount;
		if (net.count(x) == 0) net[x] = 0;
		if (net.count(y) == 0) net[y] = 0;
		net[x] -= amount;
		net[y] += amount;
	}
	multiset<pair<string, int>, person_compare>m;
	for (auto p : net) {
		string person = p.first;
		int amount = p.second;
		if (net[person] != 0) m.insert({person, amount});
	}
	//Settlement from start and end
	int cnt = 0; //Minimum number of transaction needed for settlement
	while (!m.empty()) {
		auto low = m.begin();
		auto high = prev(m.end());
		int debit = low->second;
		string debit_person = low->first;

		int credit = high->second;
		string credit_person = high->first;

		//Erase them out
		m.erase(low);
		m.erase(high);

		int settlement_amount = min(-debit, credit);
		debit += settlement_amount;
		credit -= settlement_amount;
		cnt++;
		//Print the transaction between friends
		cout << credit_person << " will pay " << settlement_amount << " to " << debit_person << endl;
		if (debit != 0) m.insert({debit_person, debit});
		if (credit != 0) m.insert({credit_person, credit});
	}
	cout << "Total transaction made between friends is " << cnt << endl;
}
