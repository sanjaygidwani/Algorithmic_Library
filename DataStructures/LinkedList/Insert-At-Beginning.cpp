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
	temp->next = head;
	head = temp;
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
	cout << "Insert element at the beginning of the list, press -1 to terminate\n";
	int n;
	while(cin >> n) {
		if(n == -1)
			break;
		insert(n);
		printList();
	}
	return 0;
}
