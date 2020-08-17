//https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

class Queue {
	int cs;
	list<int>l;
public:
	Queue() {
		cs = 0;
	}
	bool empty() {
		return cs == 0;
	}
	void push(int data) {
		l.push_back(data);
		cs++;
	}
	void pop() {
		if (!empty()) {
			cs--;
			l.pop_front();
		}
	}
	int front() {
		return l.front();
	}
};

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int freq[27] = {};
		queue<char>q;
		for (int i = 1; i <= n; i++) {
			char ch;
			cin >> ch;
			//Insert in the queue and update the frequency table
			q.push(ch);
			freq[ch - 'a']++;
			//Query
			while (!q.empty()) {
				int idx = q.front() - 'a';
				if (freq[idx] > 1)
					q.pop();
				else {
					cout << q.front() << " ";
					break;
				}
			}
			//q is empty
			if (q.empty())
				cout << "-1 ";
		}
		cout << endl;
	}
	return 0;
}
