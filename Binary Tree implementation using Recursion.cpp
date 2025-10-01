#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Recursive function to build binary tree
Node* createTree() {
    int x;
    cout << "Enter data (-1 for no root): ";
    cin >> x;

    if(x == -1) return NULL;

    // create a new node
    Node* root = new Node(x);

    // recursive call for left child
    cout << "Enter left child of " << x << endl;
    root->left = createTree();

    // recursive call for right child
    cout << "Enter right child of " << x << endl;
    root->right = createTree();

    return root;
}

int main() {
    Node* root = createTree();

    return 0;
}