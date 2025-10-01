#include <bits/stdc++.h>
using namespace std;

// structure of tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// function to create binary tree using BFS approach (level by level)
Node* createTree(){
    int x;
    cout << "Enter root data (-1 for no node): ";
    cin >> x;

    if(x == -1) return NULL;

    //creating new node
    Node* root = new Node(x);

    // use queue to build tree level by level
    queue<Node*> q;
    q.push(root);

    // process each node from the queue
    while(!q.empty()){
        Node* temp = q.front(); // curr node
        q.pop();

        // left child 
        cout << "Enter left child of " << temp->data << " (-1 for no root): ";
        cin >> x;
        if(x != -1){
            temp->left = new Node(x); // creating new node
            q.push(temp->left); // pushing left child into queue
        }

        // right child
        cout << "enter right child of " << temp->data << " (-1 for no root): ";
        cin >> x;
        if(x != -1){
            temp->right = new Node(x);
            q.push(temp->right); // pushing right child into queue
        }
    }

    return root;
}

int main() {
    // Build tree
    Node* root = createTree();

    return 0;
}
