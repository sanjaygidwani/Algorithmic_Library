// O(N), N = number of nodes in a binary tree

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
} *root = NULL;

// ------------------------------- Traversals ------------------------------- //

void preorder(Node *root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(Node *root) {
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

void postorder(Node *root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
    return;
}

void levelorder(Node *root) {
    if(root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *cur = q.front();
        cout << cur->data << " ";
        if(cur->left != NULL)
            q.push(cur->left);
        if(cur->right != NULL)
            q.push(cur->right);
        q.pop();
    }
    return;
}

// -------------------------------------------------------------------------- //

/*
    1
   / \
  2   3
 / \ / \
4  5 6  7

124 + 125 + 136 + 137 = 522

*/

long long sumPath(Node *root, long long num) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return ((num * 10) + root->data);
    long long total = 0;
    if(root->left != NULL)
        total += sumPath(root->left, (num * 10) + root->data);
    if(root->right != NULL)
        total += sumPath(root->right, (num * 10) + root->data);
    return total;
}

// -------------------------------------------------------------------------- //

int height(Node *root) {
    if(root == NULL)
        return -1;
    int l = height(root->left);
    int r = height(root->right);
    return max(l, r) + 1;
}

// -------------------------------------------------------------------------- //

int main() {
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return 0;
}
