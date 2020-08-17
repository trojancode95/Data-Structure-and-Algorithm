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

//Sort an unsorted Linked List : Merge Sort
//time complexity : O(nlogn)
Node* mergeSort(Node* head) {
	if (head == nullptr or head->next == nullptr)
		return head;
	//1)Divide about mid point
	Node* mid = midpoint(head);
	Node* a = head;
	Node* b = mid->next;
	mid->next = nullptr;
	//2)Recursively sort the two parts
	a = mergeSort(a);
	b = mergeSort(b);
	//3)Merge them
	Node* c = merge(a, b);
	return c;
}

int32_t main() {
	Node *head = nullptr;
	head = take_input();
	head = mergeSort(head);
	print(head);
}
