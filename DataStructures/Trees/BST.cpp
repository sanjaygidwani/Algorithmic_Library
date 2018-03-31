#include <bits/stdc++.h>

using namespace std;

struct bstNode {
    int data;
    bstNode* left;
    bstNode* right;
};

bstNode* getNode(int x) {
    bstNode* newNode = new bstNode();
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isBST(bstNode* root, int _min, int _max) {
    if(root == NULL)
        return 1;
    if(root->data > _min && root->data < _max && isBST(root->left, _min, root->data) && isBST(root->right, root->data, _max))
        return 1;
    return 0;
}

int findMin(bstNode* root) {
    if(root == NULL)
        return INT_MAX;
    if(root->left == NULL)
        return root->data;
    return findMin(root->left);
}

bstNode* search(bstNode* root, int x) {
    if(root == NULL)
        return root;
    else if(root->data == x)
        return root;
    else if(root->data > x)
        return search(root->left, x);
    else
        return search(root->right, x);
}

int getSuccessor(bstNode* root, int x) {
    bstNode* curr = search(root, x);
    if(curr == NULL)
        return -1;
    // Case 1 : Node has right subtree
    if(curr->right != NULL)
        return findMin(curr->right);
    // Case 2 : No right subtree
    bstNode* successor = NULL;
    bstNode* ancestor = root;
    while(ancestor != curr) {
        if(curr->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else
            ancestor = ancestor->right;
    }
    if(successor == NULL)
        return -1;
    return successor->data;
}

bstNode* Delete(bstNode* root, int x) {
    if(root == NULL)
        return root;
    else if(x < root->data)
        root->left = Delete(root->left, x);
    else if(x > root->data)
        root->right = Delete(root->right, x);
    // Wohoo! I found you. Get ready to be deleted.
    else {
        // Case 1 : No child / Leaf node
        if(root->left == NULL && root->right == NULL) {
            delete root; // Dangling pointer
            root = NULL;
        }
        // Case 2 : One child
        else if(root->left == NULL) {
            bstNode* tmp = root;
            root = root->right;
            delete tmp;
        }
        else if(root->right == NULL) {
            bstNode* tmp = root;
            root = root->left;
            delete tmp;
        }
        // Case 3 : Two childs
        else {
            int _min = findMin(root->right);
            root->data = _min;
            root->right = Delete(root->right, _min);
        }
    }
    return root;
}

bstNode* insert(bstNode* root, int data) {
    if(root == NULL)
        root = getNode(data);
    else if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int main() {
    bstNode* root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 5);
    return 0;
}
