#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

class Queue {
	int *arr;
	int f, r, cs, ms;
public:
	Queue(int ds = 5) {
		arr = new int[ds];
		cs = 0;
		ms = ds;
		f = 0;
		r = ms - 1;
	}
	bool full() {
		return cs == ms;
	}
	bool empty() {
		return cs == 0;
	}
	void push(int data) {
		if (!full()) {
			r = (r + 1) % ms;
			arr[r] = data;
			cs++;
		}
	}
	void pop() {
		if (!empty()) {
			f = (f + 1) % ms;
			cs--;
		}
	}
	int front() {
		return arr[f];
	}
	~Queue() {
		if (arr != NULL) {
			delete [] arr;
			arr = NULL;
		}
	}
};

int32_t main() {
	Queue q(7);
	for (int i = 0; i <= 6; i++)
		q.push(i);
	q.pop();
	q.pop();
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}
