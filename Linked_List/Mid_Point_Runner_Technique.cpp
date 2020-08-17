#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define FASTIO ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
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

//Return length of the Linked List
int length(Node* head) {
	int cnt = 0;
	while (head) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insertAtTail(Node* &head, int data) {
	if (head == nullptr) {
		head = new Node(data);
		return;
	}
	Node*tail = head;
	while (tail->next)
		tail = tail->next;
	tail->next = new Node(data);
}

void insertAtMiddle(Node* head, int data, int pos) {
	//Corner Case
	if (head == nullptr || pos == 0) {
		insertAtHead(head, data);
		return;
	}
	else if (pos > length(head)) {
		insertAtTail(head, data);
		return;
	}
	else {
		//take pos-1 jump to reach the position
		int jump = 1;
		Node* temp = head;
		while (jump <= pos - 1) {
			temp = temp->next;
			jump++;
		}
		//Create a new node
		Node* n = new Node(data);
		n->next = temp->next;
		temp->next = n;
	}
}

void deleteHead(Node* &head) {
	if (head == nullptr)
		return;
	Node* temp = head->next;
	delete head;
	head = temp;
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

//Mid Point Runner Technique
Node* midpoint(Node* head) {
	if (head == nullptr || head->next == nullptr)
		return head;
	Node* slow = head;
	Node* fast = head->next;
	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

int32_t main() {
	Node*head = nullptr;
	head = take_input();
	Node* mid = midpoint(head);
	print(head);
	cout << mid->data << endl;
}
