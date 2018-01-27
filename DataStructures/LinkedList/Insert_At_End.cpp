#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* head;

void insert(int n) {
	Node* temp = new Node();
	temp->data = n;
	temp->next = NULL;
	Node* temp1 = head;
	while(temp1->next != NULL)
		temp1 = temp1->next;
	temp1->next = temp;
}

void printList() {
	Node* ptr = head;
	while(ptr->next != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << ptr->data << endl;
}

int main() {
	head = NULL;
	cout << "Insert element in the list, press -1 to terminate\n";
	bool empty = 1;
	int n;
	while(cin >> n) {
		if(n == -1)
			break;
		if(empty) {
			Node* temp = new Node();
			temp->data = n;
			temp->next = NULL;
			head = temp;
			empty = 0;
		}
		else
			insert(n);
		printList();
	}
	return 0;
}
