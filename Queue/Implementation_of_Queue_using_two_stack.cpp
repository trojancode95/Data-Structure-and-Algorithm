#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

//Implement Queue using two Stack
template<typename T>
class Queue {
	stack<T>s1, s2;
public:
	bool empty() {
		return s1.empty();
	}
	void push(T data) {
		s1.push(data);
	}
	void pop() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		s2.pop();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}
	T front() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		T x = s2.top();
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
		return x;
	}
};

int32_t main() {
	Queue<int>q;
	for (int i = 1; i <= 5; i++)
		q.push(i);
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
