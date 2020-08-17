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

//Linked List class (object oriented)
// class LinkedList{
// 	Node* head;
// 	Node* tail;
// public:
// 	LinkedList(){

// 	}
// 	void insert(int data){

// 	}
// };

//Functions (Procedural Programming)
void build() {

}
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

//Search Operation : Linear Search
bool search(Node* head, int key) {
	if (head == nullptr)
		return false;
	while (head) {
		if (key == head->data)
			return true;
		head = head->next;
	}
	return false;
}

//Recursively
bool RecursivelySearch(Node* head, int key) {
	if (head == nullptr)
		return false;
	if (key == head->data)
		return true;
	return RecursivelySearch(head->next, key);
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

//Operator Overloading : cout<<head - print the entire linked list
ostream& operator<<(ostream &os, Node* head) {
	print(head);
	return os;
}
//Operator Overloading : cin>>head - input the entire linked list
istream& operator>>(istream &is, Node* &head) {
	head = take_input();
	return is;
}

int32_t main() {

	/*
	Node*  head = nullptr;
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	insertAtHead(head, 0);

	print(head);
	print(head);

	insertAtMiddle(head, 4, 3);
	insertAtTail(head, 7);
	print(head);

	deleteHead(head);
	print(head);

	cout << search(head, 4) << endl;
	cout << search(head, 5) << endl;
	cout << RecursivelySearch(head, 4) << endl;
	cout << RecursivelySearch(head, 5) << endl;
	*/
	Node* head = take_input();
	Node* head2 = take_input();
	print(head);
	print(head2);
	//cout << head; //print entire linked list..for this , we will do operator overloading
	//cout << head2;
	//cout << head << head2;
	// Node* head = nullptr;
	// Node* head2 = nullptr;
	// cin >> head >> head2;
	// cout << head << head2;
}
