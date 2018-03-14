#include <bits/stdc++.h>

using namespace std;

void insert(int heap[], int n, int item) {
    heap[n] = item;
    int ptr = n;
    int parent = (ptr >> 1);
    while(parent >= 1 && heap[ptr] < heap[parent]) {
        swap(heap[ptr], heap[parent]);
        ptr = parent;
        parent = (ptr >> 1);
    }
}

void deleteMin(int heap[], int n) {
    int val = heap[1];
    heap[1] = heap[n];
    n = n - 1;
    int ptr = 1, last = n, parent;
    bool flag = 0;
    while(!flag) {
        parent = ptr;
        if((2 * parent) <= last && heap[2 * parent] < heap[ptr])
            ptr = 2 * parent;
        if((2 * parent + 1) <= last && heap[2 * parent + 1] < heap[ptr])
            ptr = 2 * parent + 1;
        if(parent == ptr)
            flag = 1;
        else
            swap(heap[parent], heap[ptr]);
    }
}

int main() {
    cout << "enter the number of elements to insert in heap ";
    int n;
    cin >> n;
    cout << "enter elements:\n";
    int a[n + 1];
    int foo;
    for(int i = 1; i <= n; i ++) {
        cin >> foo;
        insert(a, i, foo);
    }
    for(int i = 1; i <= n; i ++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    while(1) {
        cout << "1. delete minimum\n2. exit\n\nenter your choice ";
        int x;
        cin >> x;
        if(x == 1) {
            deleteMin(a, n);
            n = n - 1;
            cout << "new min-heap:\n";
            for(int i = 1; i <= n; i ++) {
                cout << a[i] << " ";
            }
            cout << "\n";
        }
        if(x == 2)
            break;
        cout << "\n";
    }
    return 0;
}
