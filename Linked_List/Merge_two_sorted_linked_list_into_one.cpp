#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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

//Merge two Sorted Linked List into One Recursively
Node* merge(Node* head1, Node* head2) {
	//Base Case
	if (head1 == nullptr)
		return head2;
	if (head2 == nullptr)
		return head1;
	Node* head = nullptr;
	if (head1->data < head2->data) {
		head = head1;
		head->next = merge(head1->next, head2);
	}
	else {
		head = head2;
		head->next = merge(head1, head2->next);
	}
	return head;
}

int32_t main() {
	Node *head1 = nullptr, *head2 = nullptr;
	head1 = take_input();
	head2 = take_input();
	Node* head = merge(head1, head2);
	print(head);
}
