#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};
Node *head;

void insertBeg() {
	cout << "enter element: ";
	int x;
	cin >> x;
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	if(head == NULL) {
		head = temp;
		return;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;
}

void insertEnd() {
	cout << "enter element: ";
	int x;
	cin >> x;
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;
	if(head == NULL) {
		head = temp;
		return;
	}
	Node *ptr = head;
	while(ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = temp;
	temp->prev = ptr;
}

void printList() {
	Node *ptr = head;
	while(ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << "\n";
}

void printReverse() {
	Node *ptr = head;
	while(ptr->next != NULL)
		ptr = ptr->next;
	while(ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->prev;
	}
	cout << "\n";
}

int main() {
	head = NULL;
	cout << "1. insert at beginning\n2.insert at end\n3. print\n4. reverse print\n5. exit\n\n";
	int n;
	while(cin >> n) {
		if(n == 1)
			insertBeg();
		else if(n == 2)
			insertEnd();
		else if(n == 3)
			printList();
		else if(n == 4)
			printReverse();
		else if(n == 5)
			break;
		else
			cout << "invalid operation\n\n";
	}
	return 0;
}
