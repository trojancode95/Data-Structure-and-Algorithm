#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

//Implement stack using two Queue
template<typename T>
class Stack {
	queue<T>q1;
	queue<T>q2;
public:
	bool empty() {
		return q1.empty();
	}
	void push(T x) {
		q2.push(x);
		while (!q1.empty()) {
			q2.push(q1.front());
			q1.pop();
		}
		swap(q1, q2);
	}
	void pop() {
		q1.pop();
	}
	T top() {
		return q1.front();
	}
};

int32_t main() {
	Stack<int>s;
	for (int i = 1; i <= 5; i++)
		s.push(i);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}
