// Back-end complete function Template for C++
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
public:
    int find(int* in, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (in[i] == target) return i;
        }
        return -1;
    }
   
    Node* Tree1(int* in, int* post, int instart, int inend, int& index, bool& valid) {
        if (!valid || instart > inend) return nullptr;
       
        Node* root = new Node(post[index]);
        int pos = find(in, post[index], instart, inend);
        if (pos == -1 || pos < instart || pos > inend) {
            valid = false;
            return nullptr;
        }
        index--;
       
        root->right = Tree1(in, post, pos + 1, inend, index, valid);
        root->left = Tree1(in, post, instart, pos - 1, index, valid);
       
        return root;
    }
   
    Node* buildTree1(int* inorder, int* postorder, int n, bool& valid) {
        int index = n - 1;
        return Tree1(inorder, postorder, 0, n - 1, index, valid);
    }
   
    Node* Tree2(int* in, int* pre, int Instart, int Inend, int& index, bool& valid) {
        if (!valid || Instart > Inend) return nullptr;
        Node* root = new Node(pre[index]);
        index++;
        if (Instart == Inend) return root;
        int pos = find(in, root->data, Instart, Inend);
        if (pos == -1 || pos < Instart || pos > Inend) {
            valid = false;
            return nullptr;
        }
        root->left = Tree2(in, pre, Instart, pos - 1, index, valid);
        root->right = Tree2(in, pre, pos + 1, Inend, index, valid);
        return root;
    }
   
    Node* buildTree2(int* inorder, int* preorder, int n, bool& valid) {
        int index = 0;
        return Tree2(inorder, preorder, 0, n - 1, index, valid);
    }
   
    bool isSame(Node* a, Node* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr) return false;
        if (a->data != b->data) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
   
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        if (N <= 0) return false;
       
        bool valid1 = true;
        bool valid2 = true;
       
        Node* treeFromPost = buildTree1(inorder, postorder, N, valid1);
        Node* treeFromPre = buildTree2(inorder, preorder, N, valid2);
       
        if (!valid1 || !valid2) return false;
       
        return isSame(treeFromPost, treeFromPre);
    }
};