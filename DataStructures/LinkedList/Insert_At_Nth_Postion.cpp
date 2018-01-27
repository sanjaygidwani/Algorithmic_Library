#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* head;

void insert(int n, int pos) {
	Node* temp = new Node();
	temp->data = n;
	temp->next = NULL;
	if(pos == 1) {
		temp->next = head;
		head = temp;
		return;
	}
	Node* temp1 = head;
	for(int i = 1; i < pos - 1; i ++)
		temp1 = temp1->next;
	temp->next = temp1->next;
	temp1->next = temp;
}

void printList() {
	Node* ptr = head;
	while(ptr->next != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << ptr->data << "\n";
}

int main() {
	head = NULL;
	cout << "Insert element at nth position press -1 -1 to exit\n";
	int currSize = 1;
	int n, pos;
	while(cin >> n >> pos) {
		if(n == -1 && pos == -1)
			break;
		if(pos <= 0 || pos > currSize)
			cout << "Invalid postion\n";
		else {
			insert(n, pos);
			printList();
			currSize ++;
		}
	}
	return 0;
}
