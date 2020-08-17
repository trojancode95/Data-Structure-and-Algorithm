#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd

class Node {
public:
	int data;
	Node* next;
	//constructor
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

//Passing a pointer via pass by reference
void insertAtHead(Node* &head, int data) {
	if (head == nullptr) {
		head = new Node(data);
		return;
	}
	Node* n = new Node(data);
	n->next = head;
	head = n;
}

//Passing this head value via pass by value .So original head will remains same in the main.
void print(Node* head) {
	while (head) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node* take_input() {
	int data;
	cin >> data;
	Node* head = nullptr;
	while (data != -1) {
		insertAtHead(head, data);
		cin >> data;
	}
	return head;
}
//Kth Node from the end of the Linked List
void printKthNode(Node* head, int k) {
	Node* slow = head;
	Node* fast = head;
	int cnt = 1;
	while (cnt <= k) {
		cnt++;
		fast = fast->next;
	}
	while (fast) {
		slow = slow->next;
		fast = fast->next;
	}
	cout << slow-> data << endl;
}

int32_t main() {
	Node* head = nullptr;
	head = take_input();
	print(head);
	int k;
	cin >> k;
	printKthNode(head, k);
}
