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

void insert(Node* &head, int data) {
	Node* n = new Node(data);
	if (head == nullptr) {
		head = n;
		n->next = n;
	}
	else {
		n->next = head;
		Node*temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = n;
	}
}

//Floyd's Cycle : Cycle Detection & Removal
bool detectCycle(Node* head) {
	Node* slow = head;
	Node*fast = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			return true;
	}
	return false;
}

//The point where slow and fast meet ..from that point ,the distance
//from head to start of the loop is same as the distance from that
//point to the start of the loop.
void removeLoop(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
			break;
	}
	//when cycle starts from the head of the loop
	if (slow == head) {
		while (fast->next != slow)
			fast = fast->next;
		fast->next = nullptr;
	}
	else {
		slow = head;
		while (slow->next != fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = nullptr;
	}
}

//Search any node and return that node if present
Node* getNode(Node* head, int data) {
	Node* temp = head;
	//All nodes except last node
	while (temp->next != head) {
		if (temp->data == data)
			return temp;
		temp = temp->next;
	}
	if (temp->data == data)
		return temp;
	return nullptr;
}
//Deletion in a Circular Linked List
void deleteNode(Node* &head, int data) {
	Node* del = getNode(head, data);
	if (del == nullptr)
		return;
	if (head == del)
		head = head->next;
	Node* temp = head;
	//stop one step behind the node to be deleted
	while (temp->next != del)
		temp = temp->next;
	temp->next = del->next;
	delete del;
}

void print(Node* head) {
	Node* temp = head;
	while (temp->next != head) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << endl;
}

int32_t main() {
	Node *head = nullptr;
	insert(head, 10);
	insert(head, 20);
	insert(head, 30);
	insert(head, 40);
	insert(head, 50);
	print(head);
	deleteNode(head, 10);
	print(head);
}
