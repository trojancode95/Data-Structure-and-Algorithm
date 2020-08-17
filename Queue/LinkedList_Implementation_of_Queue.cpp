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
	Queue q;
	for (int i = 1; i <= 10; i++)
		q.push(i);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}
