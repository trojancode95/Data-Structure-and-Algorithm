#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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

Node* reverse(Node* head) {
	Node* prev = nullptr;
	Node* current = head;
	while (current) {
		//Save the next node
		Node* next = current->next;
		//make the current node point to prev
		current->next = prev;
		//update the prev and current one step forward
		prev = current;
		current = next;
	}
	return prev;
}

//Recursively reverse a Linked List
Node* recursiveReverse(Node* head) {
	//smallest linked list
	if (head->next == nullptr || head == nullptr)
		return head;
	//Recursive Case
	Node* shead = recursiveReverse(head->next);
	Node* temp = head->next;
	head->next = nullptr;
	temp->next = head;
	return shead;
}

int32_t main() {
	Node*head = nullptr;
	head = take_input();
	print(head);
	//head = reverse(head);
	head = recursiveReverse(head);
	print(head);
	return 0;
}
